
#ifndef MYHEADER_HPP
#define MYHEADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool readFileToString(std::string fileName, std::string &content);
bool convertContent(std::string content, const std::string &s1, const std::string &s2, std::string &newContent);
bool createWriteNewFile(std::string fileName, std::string newContent);

#endif
