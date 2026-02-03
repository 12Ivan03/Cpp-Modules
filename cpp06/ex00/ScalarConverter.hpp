
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits.h>

// it must not be instantiable by users

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();
	
	public:
	
	static void convert(const std::string &str);
};

#endif