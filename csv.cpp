#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ofstream out("marks.csv");
    if (!out) {
        std::cerr << "open failed for writing\n";
        return 1;
    }

    out << "Asha,91\nRavi,78\nMeera,88\n";
    out.close();

    std::ifstream in("marks.csv");
    if (!in) {
        std::cerr << "open failed\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string marks;

        if (std::getline(ss, name, ',') && std::getline(ss, marks, ',')) {
            std::cout << name << " => " << marks << '\n';
        }
    }
}
