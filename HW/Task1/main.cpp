#include <iostream>
#include <map>
#include <exception>

class OnlineStore {
private:
    std::map<std::string, int> database;
    std::map<std::string, int> cart;

public:
    void addToDatabase(const std::string& article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive.");
        }
        database[article] += quantity;
    }

    void addToCart(const std::string& article, int quantity) {
        if (database.find(article) == database.end()) {
            throw std::invalid_argument("Article not found in database.");
        }
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive.");
        }
        if (database[article] < quantity) {
            throw std::runtime_error("Not enough items in stock.");
        }
        cart[article] += quantity;
        database[article] -= quantity;
    }

    void removeFromCart(const std::string& article, int quantity) {
        if (cart.find(article) == cart.end()) {
            throw std::invalid_argument("Article not found in cart.");
        }
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive.");
        }
        if (cart[article] < quantity) {
            throw std::runtime_error("Not enough items in cart.");
        }
        cart[article] -= quantity;
        database[article] += quantity;
        if (cart[article] == 0) {
            cart.erase(article);
        }
    }

    void printDatabase() const {
        std::cout << "Database:\n";
        for (const auto& item : database) {
            std::cout << item.first << ": " << item.second << " items\n";
        }
    }

    void printCart() const {
        std::cout << "Cart:\n";
        for (const auto& item : cart) {
            std::cout << item.first << ": " << item.second << " items\n";
        }
    }
};

int main() {
    OnlineStore store;

    try {
        store.addToDatabase("A123", 10);
        store.addToDatabase("B456", 5);
        store.addToDatabase("C789", 20);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    store.printDatabase();

    try {
        store.addToCart("A123", 3);
        store.addToCart("B456", 2);
        store.addToCart("C789", 25);  // Это вызовет ошибку, так как нет столько товара
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    store.printCart();

    try {
        store.removeFromCart("A123", 1);
        store.removeFromCart("B456", 3);  // Это вызовет ошибку, так как в корзине только 2 товара
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    store.printCart();

    store.printDatabase();

    return 0;
}