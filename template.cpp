#include <iostream>
#include <string>

template <typename K, typename V>
struct Pair {
    K key;
    V value;

    void show() const {
        std::cout << key << " -> " << value << '\n';
    }
};

template <typename A, typename B>
auto bigger(A a, B b) {
    return (a > b) ? a : b;
}

int main() {
    Pair<std::string, int> first{"ECE", 121};
    first.show();

    Pair<int, double> second{7, 3.5};
    second.show();

    std::cout << "bigger(3, 9.5) = " << bigger(3, 9.5) << '\n';
}
