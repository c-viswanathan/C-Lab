#include <iostream>
#include <string>

class Logger {
    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& get() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << '\n';
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
}
