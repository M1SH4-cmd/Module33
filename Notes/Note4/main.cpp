#include <iostream>
#include <vector>

template<typename T>
struct Message
{
    T data;

    Message(char* data) : data(data)
    {}

    void print() const {
        std::cout << data << std::endl;
    }

};


int main() {

    Message<std::string> m("Hello, World!");
    m.print();
    return 0;
}
