
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <sstream>
#include <chrono>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

class PmergeMe {

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		size_t _vecComparisons;

		void				validateInput(int argc, char *argv[]);
		void				printContainer(int n, int when);
		std::vector<int>	sortByFordJohnsonVector(std::vector<int> sortVec);
		std::vector<int>	extractLargePairs(std::vector<std::pair<int, int>> pairVector);
		std::vector<int>	insertOrder(std::vector<int> nextLevel, std::vector<std::pair<int, int>> pairVector);
		std::deque<int>		sortByFordJohnsonDeque(std::deque<int> deqInProgress);
		std::deque<int>		extractLargePairDeq(std::deque<std::pair<int, int>> pairDeque);		
		std::deque<int>		insertDeqOrder(std::deque<int> nextLevel, std::deque<std::pair<int, int>> pairDeque);

		template <typename C>
		C buildJacobsthalSequence(size_t n) {

			C jsOrder;

			if (n == 0)
				return jsOrder;

			jsOrder.push_back(1);
			if (n == 1)
				return jsOrder;

			jsOrder.push_back(3);
			size_t a = 1;
			size_t b = 3;
			while (b < n) {
				size_t next = b + 2 * a;
				jsOrder.push_back(next);
				a = b;
				b = next;
			}

			return jsOrder;
		};

		template <typename C>
		C jacobsthalIndices(size_t n) {
				
			C order;
			
			if (n == 0)
				return order;
				
			order.push_back(0);
			if (n == 1)
				return order;
				
			// build Jacobsthal order - compare the size of the pair with the index of Jacobsthal sequence n <1 3 5 11 21...
			C jacobOrder = buildJacobsthalSequence<C>(n);
			
			// Ford-Johnson inderstion order
			for (size_t i = 1; i < jacobOrder.size(); i++) {

				size_t upper = jacobOrder[i];
				size_t lower = jacobOrder[i - 1];

				if (upper > n)
					upper = n;

				for (size_t idx = upper; idx > lower; idx--) {
					order.push_back(idx - 1);
				}
			}

			return order;
		};

	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		
};

struct CountCompare {
    size_t* counter;

    CountCompare(size_t* c) : counter(c) {}

    bool operator()(int lhs, int rhs) const {
        ++(*counter);
        return lhs < rhs;
    }
};

#endif
