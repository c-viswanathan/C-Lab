#include <iostream>
#include <queue>
#include <vector>

int main() {
    const std::vector<int> scores = {50, 90, 20, 75, 60, 95, 40};
    std::priority_queue<int> scoresByRank(scores.begin(), scores.end());

    std::cout << "Top 3 scores: ";
    for (int rank = 0; rank < 3 && !scoresByRank.empty(); ++rank) {
        std::cout << scoresByRank.top() << ' ';
        scoresByRank.pop();
    }
    std::cout << '\n';
}
