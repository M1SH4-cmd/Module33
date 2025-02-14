#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <vector>

class Fish {
public:
    Fish() {
        std::cout << "A fish is hiding in one of the sectors!\n";
    }
};

class Boot {
public:
    Boot() {
        std::cout << "A boot is hiding in one of the sectors!\n";
    }
};

class FishCaught : public std::exception {
public:
    const char* what() const noexcept override {
        return "Congratulations! You caught a fish!";
    }
};

class BootCaught : public std::exception {
public:
    const char* what() const noexcept override {
        return "Oh no! You caught a boot! Game over!";
    }
};

struct Sector {
    Fish* fish = nullptr;
    Boot* boot = nullptr;
};

int getRandomNumber(int max) {
    return std::rand() % max;
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<Sector> field(9);

    int fishSector = getRandomNumber(9);
    field[fishSector].fish = new Fish();

    for (int i = 0; i < 3; ++i) {
        int bootSector;
        do {
            bootSector = getRandomNumber(9);
        } while (field[bootSector].fish != nullptr || field[bootSector].boot != nullptr);
        field[bootSector].boot = new Boot();
    }

    int attempts = 0;
    while (true) {
        std::cout << "Enter the sector number (0-8) to use your fishing rod: ";
        int sector;
        std::cin >> sector;

        if (sector < 0 || sector > 8) {
            std::cout << "Invalid sector number. Please try again.\n";
            continue;
        }

        attempts++;

        try {
            if (field[sector].fish != nullptr) {
                throw FishCaught();
            } else if (field[sector].boot != nullptr) {
                throw BootCaught();
            } else {
                std::cout << "Nothing was caught. Try again.\n";
            }
        } catch (const FishCaught& e) {
            std::cout << e.what() << "\n";
            std::cout << "Number of attempts: " << attempts << "\n";
            break;
        } catch (const BootCaught& e) {
            std::cout << e.what() << "\n";
            break;
        }
    }

    for (Sector& sector : field) {
        delete sector.fish;
        delete sector.boot;
    }

    return 0;
}