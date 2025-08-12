
#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger.\n" \
<< "I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon \
costs more money.\n" << "You didn’t put enough bacon in my \
burger! If you did, I wouldn’t be asking for more!\n" \
<< std::endl;
}
void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra \
bacon for free.\n" << "I’ve been coming for years, \
whereas you started working here just last month.\n" \
<< std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak \
to the manager now.\n" << std::endl;
}

int findLevelInt(std::string level) {
    
    std::string arrLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (arrLevel[i] == level)
            return i;
    }

    return -1;
}

// if neccessary remove this functions and from the class and use the unelegant switch statement. :) 
void    Harl::printLevels(int level) {

    void (Harl::*ptrFun[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    while (level <  4)
        (this->*ptrFun[level++])();

}

void Harl::complain(std::string level) {

    int levelInt = findLevelInt(level);

    switch(levelInt) {
        case 0: 
            printLevels(levelInt);
            break;
        case 1:
            printLevels(levelInt);
            break;
        case 2:
            printLevels(levelInt);
            break;
        case 3:
            printLevels(levelInt);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

// switch(levelInt) {
//     case 0: 
//         this->debug(), this->info(), this->warning(), this->error();
//         break;
//     case 1:
//         this->info(), this->warning(), this->error();
//         break;
//     case 2:
//         this->warning(), this->error();
//         break;
//     case 3:
//         this->error();
//         break;
//     default:
//         std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// }
