#include <iostream>
#include <mutex>
#include <thread>

long counter = 0;
std::mutex counterMutex;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    std::thread first(addSafe, 100000);
    std::thread second(addSafe, 100000);

    first.join();
    second.join();

    std::cout << "counter = " << counter << " (expected 200000)\n";
}
