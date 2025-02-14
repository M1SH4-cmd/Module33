#include <iostream>
#include <cassert>
#include <type_traits> // Для проверки типа данных

template <typename T>
void input(T array[8]) {
    std::cout << "Fill the array (8 elements):\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }
}

template <typename T>
T calculateAverage(T array[8]) {
    assert(std::is_arithmetic<T>::value && "Type must be arithmetic (int, float, double, etc.)");

    T sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    return sum / 8;
}

int main() {
    std::cout << "Select array type (1 - int, 2 - float, 3 - double): ";
    int type;
    std::cin >> type;

    if (type == 1) {
        int array[8];
        input(array);
        int average = calculateAverage(array);
        std::cout << "Average: " << average << "\n";
    } else if (type == 2) {
        float array[8];
        input(array);
        float average = calculateAverage(array);
        std::cout << "Average: " << average << "\n";
    } else if (type == 3) {
        double array[8];
        input(array);
        double average = calculateAverage(array);
        std::cout << "Average: " << average << "\n";
    } else {
        std::cout << "Invalid type selection.\n";
    }

    return 0;
}