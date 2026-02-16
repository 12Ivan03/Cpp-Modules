
#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T>>() {};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T, std::deque<T>>(other) {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {

	if (this != &other)
		std::stack<T, std::deque<T>>::operator=(other);
	return *this;
};

template<typename T>
MutantStack<T>::~MutantStack() {};
