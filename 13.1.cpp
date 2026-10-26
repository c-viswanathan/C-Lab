#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    explicit Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

struct Square : Shape {
    explicit Square(double side) : side(side) {}

    double area() const override {
        return side * side;
    }

private:
    double side;
};

std::unique_ptr<Shape> makeShape(const std::string& kind) {
    if (kind == "circle") {
        return std::make_unique<Circle>(2.0);
    }
    if (kind == "square") {
        return std::make_unique<Square>(3.0);
    }
    throw std::invalid_argument("unknown shape: " + kind);
}

int main() {
    const auto circle = makeShape("circle");
    const auto square = makeShape("square");

    std::cout << "area circle = " << circle->area()
              << ", area square = " << square->area() << '\n';
}
