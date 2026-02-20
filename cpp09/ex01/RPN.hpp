
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <exception>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <climits>

class RPN {

	private:
		std::stack<int, std::list<int>> myStack;
		bool		checkArgv(const std::string &argv);
		bool		execution(const std::string &argv);
		long		isAritSign(char c, long a, long b);

	public:
		RPN() = delete;
		RPN(const std::string &argv);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
};

#endif