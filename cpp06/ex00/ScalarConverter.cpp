
#include "ScalarConverter.hpp"
#include <algorithm>

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

	// std::cout << "std::isinf(value): " << value << std::endl;
	std::cout << "char: " ;

	if (std::isinf(value) || std::isnan(value)) {
		std::cout << "impossible" << std::endl;
	} else if ((value >= 0 && value <= 31) || value == 127) {
		std::cout << "Non displayable" << std::endl;
	} else if (value >= 32 && value <= 126) {
		char c = static_cast<char>(value);
		std::cout << "\'" << c << "\'" << std::endl;
	} 
	else {
		std::cout << "impossible" << std::endl;
	} 

};

static void	printInt(double value) {

	std::cout << "int: ";

	if (std::isinf(value) || std::isnan(value)) {
		std::cout << "impossible" << std::endl;
	} else if (value < INT32_MIN || value > INT32_MAX) {
		std::cout << "overflow" << std::endl;
	} else if (value >= INT32_MIN && value <= INT32_MAX) {
		std::cout << static_cast<int>(value) << std::endl;
	} 
	else {
		std::cout << "impossible" << std::endl;
	} 
};

// static void	printFloat(double value) {

// };

// static void	printDouble(double value) {

// };

static void	printAll(double value) {

	printChar(value);
	printInt(value);
	// printFloat(value);
	// printDouble(value);
};

// Error functions

static void errorMessage(int er) {
	std::cout << "invalue input" << std::endl;

};

// 1. pseudoLiterals(s)

static int	pseudoLiterals(const std::string &s) {

	std::string arrLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++) {
		if (s.compare(arrLiterals[i]) == 0)
			return (i);
	}
	return (-1);
};

static int	evalPseudoLiterals(const std::string &s) {
	// std::cout << "\tpseudoLiterals" << std::endl;
	int lit = pseudoLiterals(s);
	double value;
	
	// std::cout << lit << std::endl;
	if (lit == 2 || lit == 5)
		value = std::numeric_limits<double>::quiet_NaN();
	else if (lit == 1 || lit == 4)
		value = std::numeric_limits<double>::infinity();
	else
		value = -std::numeric_limits<double>::infinity();
	printAll(value);
	return 0;
}

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
}

// function
void ScalarConverter::convert(const std::string &str) {

	std::cout << "first entry >" << str << "<" << std::endl;

	std::string s = myTrimString(str);
	
	if (pseudoLiterals(s) != -1) {
		evalPseudoLiterals(s);
		return ;
	} else if (evalStringLength(s) != -1) {
		printStringLength(s);
		return ;
	// } else if (endsOnF(s)) {
	// 	printResult();
	// } else if (strinIntDouble(s)) {
	// 	printResult();
	} else {
		// printAll(0);
		errorMessage(1);
	}
	std::cout << ">" << s << "<" << std::endl;
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



















