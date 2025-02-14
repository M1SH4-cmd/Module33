#include <iostream>
#include <vector>
#include <exception>

class VectorOperationException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "'v' can't be empty!";
    }
};

template<typename T1, typename T2>
T1 max(T1 a, T2 b)
{
    return a > b ? a : b;
}

template<typename T>


T max(std::vector<T>& v)
{
    if (v.empty()) {
        throw (VectorOperationException());
    }
    T m = v[0];
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > m) {
            m = v[i];
        }
    }
    return m;
}

int main()
{
    std::vector<double> vec1{1.2, 5.3, 15.5, 135.6654, 0.31264, 0.01001};

    try {
        std::cout << max(vec1) << std::endl;
    } catch (const VectorOperationException& x) {
        std::cerr << x.what() << std::endl;
    }

    return 0;
}