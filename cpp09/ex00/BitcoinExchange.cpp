
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
void	BitcoinExchange::populateDatabase() {
		
	std::string line;

	std::ifstream filein("./data_file/data_test.csv");
	if (!filein.is_open())
		throw std::runtime_error("data.csv: cannot open file: data.csv");

	std::getline(filein, line);
	while (std::getline(filein, line)) {

		size_t pos = line.find(",");
		if (pos == std::string::npos)
			throw std::runtime_error("data.csv: invalid format: missing comma");
		std::string strDate = line.substr(0, pos);
		std::string strRate = line.substr(pos + 1);

		std::stringstream ss(strRate);
		double rate;
		ss >> rate;
		if (ss.fail())
			throw std::runtime_error("data.csv: invalid format: garbage information");
		
		std::string leftover;
		if (ss >> leftover)
			throw std::runtime_error("data.csv: invalid format: leftover garbage information");

		_database.insert(std::make_pair(strDate, rate));
	}

	if (!filein.eof()) 
		throw  std::runtime_error("unexpected read error");

	filein.close();
};

void	BitcoinExchange::processInputFile(const std::string& inputFile) {

	std::string line;

	std::ifstream filein(inputFile);
	if (!filein.is_open())
		throw std::runtime_error(" cannot open input file");

	while (std::getline(filein, line))
		handleLine(line);

	if (!filein.eof()) 
		throw  std::runtime_error("unexpected read error here?");

	filein.close();
};

// private functions:

void	BitcoinExchange::handleLine(std::string line) {

	double inputValue;
	double dbValue;
	size_t pos = line.find("|");
	if (pos == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	const std::string stringDate = strTrim(line.substr(0, pos));
	const std::string stringRate = strTrim(line.substr(pos + 1));

	if (!isValidDate(stringDate)) 
		return ;
	if (!isValieValue(stringRate, inputValue)) 
		return ;

	dbValue = datebaseSearch(stringDate);
	if (dbValue == -1)
		return ;

	printResult(stringDate, inputValue, dbValue);
};

bool	BitcoinExchange::isValidDate(const std::string& dateStr) {

	int allDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (dateStr.length() != 10)
		return errorMessage(6);

	if (dateStr[4] != '-' || dateStr[7] != '-')
		return errorMessage(6);

	for (size_t i = 0; i < dateStr.length(); i++) {
		if (!std::isdigit(dateStr[i]) && dateStr[i] != '-')
			return errorMessage(6);
	}

	int year = std::atoi(dateStr.substr(0, 4).c_str());
	int month = std::atoi(dateStr.substr(5, 2).c_str());
	int day = std::atoi(dateStr.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return errorMessage(5);

	int monthMaxLenght = allDaysInMonth[month - 1];
	if (month == 2 && leapYear(year))
		monthMaxLenght = 29;

	if (day < 1 || day > monthMaxLenght)
		return errorMessage(4);

	return true;
};

bool	BitcoinExchange::isValieValue(const std::string& rateStr, double &value) {

	bool dot = false;

	if (rateStr.empty())
		return errorMessage(3);

	if (rateStr[0] == '+')
		return errorMessage(3);

	for (size_t i = 0; i < rateStr.length(); i++) {

		if (i == 0 && rateStr[i] == '-')
			continue ; 
		if (rateStr[i] == '.') {
			if (dot)
				return errorMessage(3);
			if (i == 0)
				return errorMessage(3);
			if (i + 1 >= rateStr.length())
				return errorMessage(3);
			if (!std::isdigit(static_cast<unsigned char>(rateStr[i - 1])) || 
				!std::isdigit(static_cast<unsigned char>(rateStr[i + 1])))
				return errorMessage(3);
			dot = true;
			continue ;
		}
		if (!std::isdigit(static_cast<unsigned char>(rateStr[i])))
			return errorMessage(3);
	}

	std::stringstream ss(rateStr);
	double rate;
	ss >> rate;
	if (ss.fail())
		return errorMessage(3);

	std::string leftover;
	if (ss >> leftover)
		return errorMessage(3);

	if (rate < 0.0000)
		return errorMessage(1);
	if (rate > 1000.0000)
		return errorMessage(2);
	value = rate;
	return true;
};

double	BitcoinExchange::datebaseSearch(const std::string &stringDate) {

	std::map<std::string, double>::const_iterator it = _database.lower_bound(stringDate);

	if (it == _database.end()) {
		--it;
	} else if (it->first != stringDate) {

		if (it == _database.begin()) {
			return (errorMessage(7), -1);
		}
		--it;
	}
	return it->second;
};

// private : helper functions / errorMessage()

void	BitcoinExchange::printResult(const std::string &stringDate, double &inputValue, double &dbValue) {

	double res = inputValue * dbValue;
	std::cout << stringDate << " => " << inputValue << " = " << res << std::endl;
}

bool	BitcoinExchange::leapYear(int year) {

	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return (year % 4 == 0);
};

std::string	BitcoinExchange::strTrim(std::string st) {

	size_t start = 0;
	size_t end = st.length();

	while (start < st.length() && std::isspace(st[start]))
		start++;
	while (end > start && std::isspace(st[end - 1]))
		end--;

	std::string res = st.substr(start, end - start);
	return res;
};

bool	BitcoinExchange::errorMessage(int er) {

	std::cout << "Error: ";
	if (er == 1)
		std::cout << "not a positive number." << std::endl;
	if (er == 2)
		std::cout << "too large a number." << std::endl;
	if (er == 3)
		std::cout << "wrong input: not a valid number" << std::endl;
	if (er == 4)
		std::cout << "invalid day of the month" << std::endl;
	if (er == 5)
		std::cout << "invalide month of the year" << std::endl;
	if (er == 6)
		std::cout << "invalud date format: YYYY-MM-DD" << std::endl;
	if (er == 7)
		std::cout << "the input date is smaller than the smallest key in the map" << std::endl;
	return false;
}
