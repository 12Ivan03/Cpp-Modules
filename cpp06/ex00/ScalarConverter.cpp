
#include "ScalarConverter.hpp"
#include <algorithm>
#include <iomanip>

// OCF:
ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	return *this;
};

ScalarConverter::~ScalarConverter() {};

// 0. utils

std::string	myTrimString(const std::string &str) {
	
	int start;
	int end;

	if (str.length() == 1)
		return str;
	for (start = 0; start < str.length() && str[start] == ' '; start++);
	for (end = str.length() - 1; end > 0 && str[end] == ' '; end--);

	return str.substr(start, end - start + 1);
}

// printing functions

static void	printChar(double value) {

	std::cout << "char: " ;

	if (std::isinf(value) || std::isnan(value)) {
		std::cout << "impossible" << std::endl;
	} else if ((value >= 0 && value <= 31) || value == 127) {
		std::cout << "Non displayable" << std::endl;
	} else if (value >= 32 && value <= 126) {
		char c = static_cast<char>(value);
		std::cout << "\'" << c << "\'" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	} 

};

static void	printInt(double value) {

	std::cout << "int: ";

	if (std::isinf(value) || std::isnan(value)) {
		std::cout << "impossible" << std::endl;
	} else if (value < INT32_MIN || value > INT32_MAX) {
		std::cout << "impossible" << std::endl;
	} else if (value >= INT32_MIN && value <= INT32_MAX) {
		std::cout << static_cast<int>(value) << std::endl;
	} 
	else {
		std::cout << "impossible else" << std::endl;
	} 
};

static void	printFloat(double value) {

	std::cout << "float: ";
	float output = static_cast<float>(value);

	if  (std::isnan(value)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(value) || std::isinf(output)) {
		std::cout << (output > 0 ? "+inff" : "-inff") << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << output << "f" <<std::endl;
	}
};

static void	printDouble(double value) {

	std::cout << "double: ";

	if  (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	} else {
		// std::cout << std::fixed << std::setprecision(1) <<  value << std::endl;
		std::cout << value << std::endl;
	}
};

static void	printAll(double value) {

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
};

// Error functions

static void errorMessage(int er) {

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
};

// 1. evalPseudoLiterals(s)

static int	evalPseudoLiterals(const std::string &s) {

	std::string arrLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++) {
		if (s.compare(arrLiterals[i]) == 0)
			return (i);
	}
	return (-1);
};

static void	printPseudoLiterals(const std::string &s) {

	int lit = evalPseudoLiterals(s);
	double value;
	
	if (lit == 2 || lit == 5)
		value = std::numeric_limits<double>::quiet_NaN();
	else if (lit == 1 || lit == 4)
		value = std::numeric_limits<double>::infinity();
	else
		value = -std::numeric_limits<double>::infinity();
	printAll(value);
};

// 2. evalStringLength(s)

static int	evalStringLength(const std::string &s) {

	int sLen = s.length();

	if (sLen == 1) {
		if (isdigit(s[0]))
			return (-1);
		return (1);
	} else if (sLen == 3 && (s[0] == '\'' && s[2] == '\'')) {
		return (1);
	}
	return (-1);
};

static void	printStringLength(const std::string &s)
{
	double value;
	int index = 0;

	if (s.length() == 3)
		index = 1;
	value = static_cast<double>(s[index]);
	printAll(value);
};

// 3. evalEndsOnF(s)

static int	evalEndsOnF(const std::string &s) {

	int sLen = s.length() - 1;
	int dot = 0;
	char *end = nullptr;
	double value = strtod(s.c_str(), &end);

	if (end == s.c_str())
		return (-1);
	
	for (int i = sLen - 1; i >= 0; i--) {
		if (i == 0 && ((s)[i] == '-' || (s)[i] == '+')) {
			continue ;
		}
		if ((s)[i] == '.' && i != 0)
		{
			if (!isdigit((s)[i - 1]) || !isdigit((s)[i + 1])) 
				return (-1);
			dot++;
		} else if (!isdigit((s)[i]))
			return (-1);
	}

	if (dot == 1)
		return(1);

	return (-1);
};

static void	printEndsOnF(const std::string &s) {

	double value = strtod(s.c_str(), nullptr);
	printAll(value);
};

// 4. evalStrinIntDouble(s)

static int	evalStrinIntDouble(const std::string &s) {

	int sLen = s.length();
	// std::cout << "double " << std::endl;

	char *end = nullptr;
	double value = strtod(s.c_str(), &end);
	// std::cout << "double value = strtod() ===> " << end[0] << std::endl;

	if (end == s.c_str())
		return (-1);
	if (end[0] == '\0')
		return (1);
	return (-1);
};

static void	printStrinIntDouble(const std::string &s) {

	double value = strtod(s.c_str(), nullptr);
	printAll(value);
};

// function
void ScalarConverter::convert(const std::string &str) {

	// std::cout << "first entry >" << str << "<" << std::endl;

	std::string s = myTrimString(str);
	
	if (evalPseudoLiterals(s) != -1) {
		printPseudoLiterals(s);
	} else if (evalStringLength(s) != -1) {
		printStringLength(s);
	} else if (evalEndsOnF(s) != -1) {
		printEndsOnF(s);
	} else if (evalStrinIntDouble(s) != -1) {
		printStrinIntDouble(s);
	} else {
		errorMessage(1);
	}
	// std::cout << ">" << s << "<" << std::endl;
};

// special (nan, inf)
// char ('a' or a)
// int (42)
// float (4.2f)
// double (4.2)
// otherwise invalid



/*

string function calls for printing(int status) {
	if 0
		printf impossible
	if 1
		printf the ASCII number Char => num
	if 2 
		check if can be printed as ASCII number. num => char
}

if (argv != 2)
	error message
s == argv[1];

stages:
1. if s == {double=> "nan", "+inf", "-inf", float=> "nanf", "+inff", "-inff"}
	string function calls for printing(0).
	double value = std::numeric_limits<double>::quiet_NaN();
	double value = std::numeric_limits<double>::infinity();
	double value = -std::numeric_limits<double>::infinity();

2. if length(s) == 3 and patern = "'X'"
	convert cast according to ASCII 
	string function calls for printing(1).
3. if length(s) == 1
	call the same function as 2.
	string function calls for printing(1).

4. if s[end] == f
	parse core with strtof and or strtod
	if ok
		string function calls for printing(2).
		printf values
	else
		error impossible

5. parse with strtod //. for int and double
	if ok
		string function calls for printing(3).
		print all 
	else 
		error impossible.

6. else 
	impossible

*/


// ./convert 12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678989001234567899001123456789012345678902345678901234567890123456789023456789012345678901234567890123456789012345678912345678901234567890123456789123456789012345678901234567809012345678901234567892345678901234567890123456789123456789012345678923456789