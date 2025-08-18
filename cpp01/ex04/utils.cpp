
#include "myHeader.hpp"

bool createWriteNewFile(std::string fileName, std::string newContent) {

    std::ofstream outputFile(fileName + ".replace");
    if (!outputFile) 
        return errorHandler(4, fileName);
    outputFile << newContent;
    outputFile.close();

    cuccessMessage(fileName);

    return true;
}

bool readFileToString(std::string fileName, std::string &content) {

    std::ifstream inputFile(fileName);
    if (!inputFile) 
        return errorHandler(1, fileName);
    else if (inputFile.peek() == std::ifstream::traits_type::eof()) 
        return errorHandler(2, fileName);

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    content = buffer.str();

    return true;
}

bool convertContent(std::string content, const std::string &s1, \
                    const std::string &s2, std::string &newContent) {

    size_t pos = 0;

    if (s1.empty())
        return errorHandler(3, "");

    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    newContent = content;

    return true;
}
