
#include "RPN.hpp"

//OCF
RPN::RPN(const RPN &other) : myStack(other.myStack) {};

RPN& RPN::operator=(const RPN &other) {

	if (this != &other) {
		this->myStack = other.myStack;
	}

	return *this;
};

RPN::~RPN() {};

RPN::RPN(const std::string &argv) {

	if (!execution(argv))
		throw std::runtime_error("");

};

bool		RPN::execution(const std::string &argv) {

	if (!checkArgv(argv))
		return false;

	std::istringstream myStream(argv);
	std::string s;

	while (myStream >> s) {

		if (s.size() != 1)
			return false;

		unsigned char c = static_cast<unsigned char>(s[0]);

		if (std::isdigit(c)) {
			myStack.push(static_cast<int>(c - '0'));
		} else if (c == '*' || c == '-' || c == '+' || c == '/') {

			if (myStack.size() < 2)
				return false;

			long a = static_cast<long>(myStack.top());
			myStack.pop();
			long b = static_cast<long>(myStack.top());
			myStack.pop();

			if (c == '/' && a == 0)
				return false;

			long res = isAritSign(static_cast<char>(c), a, b);

			if (res > INT_MAX || res < INT_MIN)
				return false;

			myStack.push(static_cast<int>(res));

		} else 
			return false;
	}

	if (myStack.size() > 1)
		return false;
	int finalRes = myStack.top();

	std::cout << finalRes << std::endl;

	return true;
};

//helper private functions: 

long	RPN::isAritSign(char c, long a, long b) {
	
	if (c == '*') {
		return b * a;
	} else if  (c == '-') {
		return b - a;
	} else if  (c == '+') {
		return b + a;
	} else
		return b / a;	
}

bool	RPN::checkArgv(const std::string &argv) 
{
	int i = 0;

	if (argv.size() == 1 && !std::isdigit(static_cast<unsigned char>(argv[0])))
		return false;

	for  (; std::isspace(static_cast<unsigned char>(argv[i])); i++) {};

	if (argv[i] == '\0')
		return false;
	
	return true;
}

//  ~~~~~~~~~~~~~~~~~~~~~ PRINT MY STACK ~~~~~~~~~~~~~~~~~~~~~ //

	// std::stack<int, std::list<int>> tmp = myStack;
	// while (!tmp.empty()) {
	// 	std::cout << "myStacj : \"" << tmp.top() << "\"" << std::endl;
	// 	tmp.pop();
	// }

//  ~~~~~~~~~~~~~~~~~~~~~ -------------- ~~~~~~~~~~~~~~~~~~~~~ //
// ex01 stack < int, std::list<int> >
// ex02 std::vector<int> std::deque<int>

// first check if argv 
// " \t\t\t " -> error / "3" -> valid? 

// start execution:

/// IF number -> put numbers in the stack -> contains only sigle digit numbers

//  IF ( *, /, +, - ). anyhting else -> error
// devision by zero - if I have / the second token is 0 -> error
// overflow...
// if I have only one number in the stack and next token is operator - > error
// if argv ends and I have more than 1 number in the stack -> error

// After finishing → stack.size() must be exactly 1