
#include "myHeader.hpp"

bool createWriteNewFile(std::string fileName, std::string newContent) {

    std::ofstream outputFile(fileName + ".replace");
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file: " << fileName + ".replace" << std::endl;
        return false;
    }

    outputFile << newContent;
    outputFile.close();
    std::cout << "Content of '" << fileName << "' file has been successfully modified." << std::endl;

    return true;
}

bool readFileToString(std::string fileName, std::string &content) {

    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error: Cannot open file: '" << fileName << "' check if file name is currect." << std::endl;
        return false;
    }
    else if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: File '" << fileName << "' is empty " << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    content = buffer.str();

    return true;
}

bool convertContent(std::string content, const std::string &s1, const std::string &s2, std::string &newContent) {

    size_t pos = 0;

    if ( s1.empty() ) {
        std::cerr << "Error: Invalid strings provided for replacement." << std::endl;
        return false;
    }

    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();;
    }
    newContent = content;

    return true;
}
