
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void appendLog(const std::string& file, const std::string& entry) {
    std::ofstream log(file, std::ios::app);
    if (!log) {
        throw std::runtime_error("log open failed: " + file);
    }
    log << entry << '\n';
}

int main() {
    try {
        appendLog("run.log", "TEST started");
        appendLog("run.log", "TEST passed");

        std::ifstream in("run.log");
        if (!in) {
            throw std::runtime_error("cannot read run.log");
        }

        std::string line;
        int lines = 0;
        while (std::getline(in, line)) {
            ++lines;
        }

        std::cout << "run.log now has " << lines << " line(s)\n";
    } catch (const std::exception& e) {
        std::cerr << "I/O error: " << e.what() << '\n';
        return 1;
    }
}
