
#include "myHeader.hpp"

bool errorHandler(int er, std::string str) {
    
    if (er == 1)
       std::cerr << "Error: Cannot open file: '" << str << "' check if file name is currect." << std::endl;
    else if (er == 2)
        std::cerr << "Error: File '" << str << "' is empty " << std::endl;
    else if (er == 3)
        std::cerr << "Error: Invalid strings provided for replacement." << std::endl;
    else if (er == 4)
        std::cerr << "Error: Cannot create output file: " << str + ".replace" << std::endl;
   return false;
}

int errorHandlerInt(int er) {

    if (er == 1)
        std::cout << "Incurrect input.\n\nExample valid input:\n./program fileName \"s1\" \"s2\"" << std::endl;
    return 1;
}

void    cuccessMessage(std::string str) {
     std::cout << "Content of '" << str << "' file has been successfully modified." << std::endl;
}