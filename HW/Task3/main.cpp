#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename K, typename V>
struct KeyValuePair {
    K key;
    V value;

    KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
};

template <typename K, typename V>
class Registry {
private:
    std::vector<KeyValuePair<K, V>> data;

public:
    void add(const K& key, const V& value) {
        data.push_back(KeyValuePair<K, V>(key, value));
    }

    void remove(const K& key) {
        typename std::vector<KeyValuePair<K, V>>::iterator it = std::remove_if(data.begin(), data.end(),
                                                                               [&key](const KeyValuePair<K, V>& pair) {
                                                                                   return pair.key == key;
                                                                               });
        data.erase(it, data.end());
    }

    void print() const {
        for (typename std::vector<KeyValuePair<K, V>>::const_iterator it = data.begin(); it != data.end(); ++it) {
            std::cout << "Key: " << it->key << ", Value: " << it->value << "\n";
        }
    }

    std::vector<V> find(const K& key) const {
        std::vector<V> result;
        for (typename std::vector<KeyValuePair<K, V>>::const_iterator it = data.begin(); it != data.end(); ++it) {
            if (it->key == key) {
                result.push_back(it->value);
            }
        }
        return result;
    }
};

template <typename K, typename V>
void handleCommands() {
    Registry<K, V> registry;
    std::string command;

    while (true) {
        std::cout << "Enter command (add, remove, print, find, exit): ";
        std::cin >> command;

        if (command == "add") {
            K key;
            V value;
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            registry.add(key, value);
        } else if (command == "remove") {
            K key;
            std::cout << "Enter key: ";
            std::cin >> key;
            registry.remove(key);
        } else if (command == "print") {
            registry.print();
        } else if (command == "find") {
            K key;
            std::cout << "Enter key: ";
            std::cin >> key;
            std::vector<V> result = registry.find(key);
            if (result.empty()) {
                std::cout << "No elements found with key: " << key << "\n";
            } else {
                std::cout << "Elements with key " << key << ":\n";
                for (typename std::vector<V>::const_iterator it = result.begin(); it != result.end(); ++it) {
                    std::cout << *it << "\n";
                }
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
}

int main() {
    std::cout << "Select key type (1 - int, 2 - double, 3 - std::string): ";
    int keyType;
    std::cin >> keyType;

    std::cout << "Select value type (1 - int, 2 - double, 3 - std::string): ";
    int valueType;
    std::cin >> valueType;

    if (keyType == 1 && valueType == 1) {
        handleCommands<int, int>();
    } else if (keyType == 1 && valueType == 2) {
        handleCommands<int, double>();
    } else if (keyType == 1 && valueType == 3) {
        handleCommands<int, std::string>();
    } else if (keyType == 2 && valueType == 1) {
        handleCommands<double, int>();
    } else if (keyType == 2 && valueType == 2) {
        handleCommands<double, double>();
    } else if (keyType == 2 && valueType == 3) {
        handleCommands<double, std::string>();
    } else if (keyType == 3 && valueType == 1) {
        handleCommands<std::string, int>();
    } else if (keyType == 3 && valueType == 2) {
        handleCommands<std::string, double>();
    } else if (keyType == 3 && valueType == 3) {
        handleCommands<std::string, std::string>();
    } else {
        std::cout << "Invalid type selection.\n";
    }

    return 0;
}