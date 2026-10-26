#include <iostream>
#include <string>

template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
class Stack {
    T data[100];
    int top = -1;

public:
    void push(const T& value) {
        if (top == 99) {
            throw std::overflow_error("stack is full");
        }
        data[++top] = value;
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("stack is empty");
        }
        return data[top--];
    }

    bool empty() const {
        return top < 0;
    }
};

int main() {
    std::cout << maxOf(3, 7) << ' '
              << maxOf(2.5, 1.1) << ' '
              << maxOf<std::string>("apple", "mango") << '\n';

    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << stack.pop() << ' ';
    }
    std::cout << '\n';
}