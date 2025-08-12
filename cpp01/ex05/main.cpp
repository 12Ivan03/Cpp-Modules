
#include "Harl.hpp"

int main() {
    Harl harl;

    std::string posLevels[5] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "UNKNOWN"
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "Complain level: " << posLevels[i] << std::endl;
        harl.complain(posLevels[i]);
        std::cout << std::endl;
    }

    return 0;
}