
#include "BitcoinExchange.hpp"

// OCT
BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    this->_database = other._database;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {

    if (this != &other)
        this->_database = other._database;
    return *this;
};

BitcoinExchange::~BitcoinExchange() {};

// public functions
void    BitcoinExchange::populateDatabase() {
        
    std::string line;

    std::ifstream filein("./data_file/data_test.csv");
    if (!filein.is_open())
        throw std::runtime_error(" cannot open file: data.csv");

    std::getline(filein, line);
    while (std::getline(filein, line)) {

        size_t pos = line.find(",");
        if (pos == std::string::npos)
            throw std::runtime_error("invalid format: missing comma");
        std::string strDate = line.substr(0, pos);
        std::string strRate = line.substr(pos + 1);

        std::stringstream ss(strRate);
        double rate;
        ss >> rate;
        if (ss.fail())
            throw std::runtime_error("invalid format: garbage information");

        _database.insert(std::make_pair(strDate, rate));
    }

    if (!filein.eof()) 
        throw  std::runtime_error("unexpected read error");

    filein.close();
};

void    BitcoinExchange::processInputFile(const std::string& inputFile) {

    // std::cout << inputFile << std::endl;
    std::string line;

    std::ifstream filein(inputFile);
    if (!filein.is_open())
        throw std::runtime_error(" cannot open file: data.csv");

    // std::getline(filein, line);
    while (std::getline(filein, line)) {
        // std::cout << line << std::endl;
        handleLine(line);
    }

    if (!filein.eof()) 
        throw  std::runtime_error("unexpected read error here?");

    filein.close();
};


// private functions:

void    BitcoinExchange::handleLine(std::string line) {


    std::cout << "handleLine ------> " << line << std::endl;

    size_t pos = line.find("|");
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }

    const std::string stringDate = strTrim(line.substr(0, pos));
    const std::string stringRate = strTrim(line.substr(pos + 1));

    // std::cout << "stringDate =>" << stringDate << "<" << std::endl;
    std::cout << "stringRate =>" << stringRate << "<" << std::endl;

    if (!isValidDate(stringDate)) {
        std::cout << "\nError: bad input => " << stringDate << "\n\n" << std::endl;
        return ;
    }
    
    
    if (!isValieValue(stringRate)) {
        std::cout << "\nError: bad input => " << (stringRate.empty() ? "empty" : stringRate) << "\n\n" << std::endl;
        return ;
    }


    // std::stringstream ss(stringRate);
    // double rate;
    // ss >> rate;
    // if (ss.fail())
    //     throw std::runtime_error("invalid format: garbage information");
    // std::cout << "stringRate in double  =>" << std::fixed << rate << "<" << std::endl;
        

    // std::cout << std::endl;
};

bool		BitcoinExchange::isValidDate(const std::string& dateStr) {
    std::cout << "dateStr from isValidDate =>" << dateStr << "<" << std::endl;

    int allDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dateStr.length() != 10){
        // std::cout << "here" << std::endl;
        return false;
    }


    if (dateStr[4] != '-' || dateStr[7] != '-'){
        // std::cout << "here2" << std::endl;
        return false;
    }


    for (size_t i = 0; i < dateStr.length() - 1; i++) {
        // std::cout << "!std::isalnum(dateStr[i]) =>" << !std::isalnum(dateStr[i]) << "<     ------      >" << 
        // "!(dateStr[i] == '-') =>" << !(dateStr[i] == '-') << std::endl;
        if (!std::isdigit(dateStr[i]) && dateStr[i] != '-'){
            // std::cout << "loop-here3" << std::endl;
            return false;
        }
    }

    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    if (month < 1 || month > 12){
        // std::cout << "month-here4" << std::endl;
        return false;
    }

    int monthMaxLenght = allDaysInMonth[month - 1];
    if (monthMaxLenght == 2 && leapYear(year))
        monthMaxLenght = 29;

    if (day < 1 || day > monthMaxLenght)
        return false;

    return true;
};

bool		BitcoinExchange::isValieValue(const std::string& rateStr) {

    bool dot = false;

    if (rateStr.empty())
        return false;

    if (rateStr[0] == '+')
        return false;

    // for (size_t i = 0; i < rateStr.length(); i++) {

    //     if (i == 0 && rateStr[i] == '-')
    //         continue ; 
    //     if (rateStr[i] == '.') {
    //         if (dot)
    //             return false;
    //         dot = true;
    //         continue ;
    //     }
    //     if (!std::isdigit(static_cast<unsigned int>(rateStr[i]))){
    //         // std::cout << "here123" << std::endl;
    //         return false;
    //     }
    // }

    std::stringstream ss(rateStr);
    double rate;
    ss >> rate;

    if (ss.fail())
        return false;
    // std::cout << "stringRate in double  =>" << std::fixed << rate << "<" << std::endl;
    // std::cout << std::endl;

    std::string leftover;
    if (ss >> leftover)
        return false;
    
    if (rate < 0.0000 || rate > 1000.0000)
        return false;
    return true;
};

bool        BitcoinExchange::leapYear(int year) {

    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
};

std::string BitcoinExchange::strTrim(std::string st) {

    // std::cout << "st =>" << st << std::endl;

    size_t start = 0;
    size_t end = st.length();

    while (start < st.length() && std::isspace(st[start]))
        start++;
    while (end > start && std::isspace(st[end - 1]))
        end--;

    // std::cout << "start =>" << start << "end =>" << end << std::endl;
    std::string res = st.substr(start, end - start);
    // std::cout << "res =>" << res << "<" << std::endl;
    return res;
};



// 2011-01-03 | -3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42 |
// 2012-01-11 | 1
// 2012-11-11 | 2147483648