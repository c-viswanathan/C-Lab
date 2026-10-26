#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("students.txt");
    if (!out) {
        std::cerr << "cannot open for write\n";
        return 1;
    }

    out << "Asha 91\n"
        << "Ravi 78\n"
        << "Meera 88\n";

    std::ifstream in("students.txt");
    if (!in) {
        std::cerr << "cannot open for read\n";
        return 1;
    }

    std::string name;
    int marks;
    int total = 0;
    int count = 0;

    while (in >> name >> marks) {
        std::cout << name << " scored " << marks << '\n';
        total += marks;
        ++count;
    }

    if (count != 0) {
        std::cout << "Average = " << static_cast<double>(total) / count << '\n';
    }
}
