
#include "PmergeMe.hpp"
#include <unistd.h>

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

    validateInput(argc, argv);

    printContainer(1, 1);
    auto startVec = std::chrono::high_resolution_clock::now();
    sortByFordJohnsonVector();
    auto stopVec = std::chrono::high_resolution_clock::now();
    printContainer(1, 2);
    double durationVec = std::chrono::duration<double>(stopVec - startVec).count();

    printContainer(2, 1);
    auto startDeq = std::chrono::high_resolution_clock::now();
    sortByFordJohnsonDeque();
    sleep(10);
    auto stopDeq = std::chrono::high_resolution_clock::now();
    printContainer(2, 2);

    double durationDeq = std::chrono::duration<double>(stopDeq - startDeq).count();
    // auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(stopDeq - startDeq);

    std::cout << std::fixed << std::setprecision(6);
    std::cout  << "Time to process a range of " 
                << _vec.size() 
                << " elements with std::vector<int> : " 
                << durationVec
                << " us" << std::endl;
    std::cout  << "Time to process a range of " 
                << _deq.size() << " elements with std::deque<int> : " 
                << durationDeq 
                << " us" 
                << std::endl;
    std::cout << std::defaultfloat;

};

void    PmergeMe::sortByFordJohnsonVector() {

    // sort sort sort VECTOR
};

void    PmergeMe::sortByFordJohnsonDeque() {

    // DEQUE sort here :P
};

void    PmergeMe::printContainer(int n, int when) {

    if (when == 1)
        std::cout << "Before: ";
    else 
        std::cout << "After: ";
    if (n == 1) {
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
	    	std::cout << *it << " ";
    	}
        std::cout << std::endl;
    } else {
        for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it) {
		    std::cout << *it << " ";
	    }
        std::cout << std::endl;

    }
};

void    PmergeMe::validateInput(int argc, char *argv[]) {

    if (argc <= 1)
        throw std::runtime_error("correct input: ./Program \' shuf -i LO-HI -n N || jot -r 1 $min $max \'");
    
    for (int i = 1; i < argc; i++) {

        std::istringstream argvString(argv[i]);
        std::string s;

        while (argvString >> s) {
            
            std::cout << "s is => >" << s << "<" << std::endl;

            std::istringstream conv(s);
            long long num = 0;
            conv >> num;
            if (!s.empty() && s[0] == '+')
                throw std::runtime_error("incorrect input 1 ");
            if (conv.fail())
                throw std::runtime_error("incorrect input 2 ");
            std::string leftover;
            if (conv >> leftover)
                throw std::runtime_error("incorrect input 3 ");

            if (num <= 0)
                throw std::runtime_error("only positive numbers");
            if (num > INT_MAX)
                throw std::runtime_error("very large positve number");

            _vec.push_back(static_cast<int>(num));
            _deq.push_back(static_cast<int>(num));
        }
        // std::cout << "all good" << std::endl;
    }
};

