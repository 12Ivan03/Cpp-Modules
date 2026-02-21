
#include "PmergeMe.hpp"

// OCF
// PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {};

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(int argc, char *argv[]) {

    if (argc <= 1)
        throw std::runtime_error("correct input: ./Program \' shuf -i LO-HI -n N || jot -r 1 $min $max \'");
    
    for (int i = 1; i < argc; i++) {

        std::istringstream argvString(argv[i]);
        std::string s;

        std::cout << "argv is => >" << argv[i] << "<" << std::endl;
        if (s[0] == '\0')
                throw std::runtime_error("incorrect input");

        while (argvString >> s) {
            
            std::cout << "s is => >" << s << "<" << std::endl;

            std::istringstream conv(s);
            long long num = 0;
            conv >> num;
            if (!s.empty() && s[0] == '+')
                throw std::runtime_error("incorrect input");
            if (conv.fail())
                throw std::runtime_error("incorrect input");
            std::string leftover;
            if (conv >> leftover)
                throw std::runtime_error("incorrect input");

            if (num <= 0)
                throw std::runtime_error("only positive numbers");
            if (num > INT_MAX)
                throw std::runtime_error("very large positve number");

        }
        std::cout << "all good" << std::endl;

    }


};