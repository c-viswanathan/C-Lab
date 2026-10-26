#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::vector<Student> students = {
        {"Asha", 88}, {"Ravi", 95}, {"Meera", 72}
    };

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.marks > b.marks;
              });

    for (const auto& student : students) {
        std::cout << student.name << ' ' << student.marks << '\n';
    }

    const int passed = std::count_if(
        students.begin(), students.end(),
        [](const Student& student) { return student.marks >= 75; });
    std::cout << "Passed: " << passed << '\n';

    const int total = std::accumulate(
        students.begin(), students.end(), 0,
        [](int sum, const Student& student) { return sum + student.marks; });
    std::cout << "Total: " << total << '\n';
}
