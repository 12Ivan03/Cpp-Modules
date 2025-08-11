
#include "myHeader.hpp"

bool    analizeInputProgram(char *argv[]) {
    
    std::string fileName = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    std::string content = "";
    std::string newContent = "";
    
    if (!readFileToString(fileName, content))
        return false;
    if (!convertContent(content, s1, s2, newContent))
        return false;
    if (!createWriteNewFile(fileName, newContent))
        return false;

    return true;
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cout << "Incurrect input.\n\nExample valid input:\n./program fileName \"s1\" \"s2\"" << std::endl;
        return 1;
    }
    if (!analizeInputProgram(argv))
        return 1;
    return 0;
}
