
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <sstream>

#include <iomanip>

class BitcoinExchange {

	private:
		std::map<std::string, double> _database;
		
		void		handleLine(std::string line);
		std::string	strTrim(std::string st);
		bool		isValidDate(const std::string& dateStr);
    	bool		isValieValue();
		// bool		isStringOnlyNumber(const std::string& dateStr);
		bool		leapYear(int year);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	populateDatabase();
		void	processInputFile(const std::string& inputFile);
};

#endif
