
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

// !!!! IMPORTANT !!!!
// REMOVE THE DATA_FILE AND INPUT_FILE FROM EX00 !!!!!!!!!!!!!!
// standart error std::


class BitcoinExchange {

	private:
		std::map<std::string, double> _database;
		
		void		handleLine(std::string line);
		std::string	strTrim(std::string st);
		bool		isValidDate(const std::string& dateStr);
		bool		isValieValue(const std::string& rateStr, double &value);
		double		datebaseSearch(const std::string &stringDate);
		void		printResult(const std::string &stringDate, double &stringRate, double &dbValue);
		bool		leapYear(int year);
		bool		errorMessage(int er);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	populateDatabase();
		void	processInputFile(const std::string& inputFile);
};

#endif
