
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

// Container Adapter
// Stack is wrapper -> by default uses deque<T>
// hides the underling functions of the atual container
// provides limited access to only certnat calls.
//		 MutantStack<T>
// 		    inherits
// 		std::stack<T, std::deque<T>>
//     		contains
// 		std::deque<T>
//  		   stores
// 		T values

template<typename T>
class MutantStack : public std::stack<T, std::deque<T>> {

	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif