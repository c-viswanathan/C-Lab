
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values = {3, 8, 1, 9, 4};
    const auto first = std::find_if(
        values.begin(), values.end(), [](int value) { return value > 5; });

    if (first != values.end()) {
        std::cout << "first > 5 : " << *first << '\n';
    }

    std::sort(values.begin(), values.end());
    const auto lower = std::lower_bound(values.begin(), values.end(), 4);
    std::cout << "lower_bound(4) index = "
              << (lower - values.begin()) << '\n';

    std::vector<int> permutation = {1, 2, 3};
    std::cout << "perms: ";
    do {
        for (int value : permutation) {
            std::cout << value;
        }
        std::cout << ' ';
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    std::cout << '\n';
}
