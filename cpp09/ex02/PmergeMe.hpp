
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
		size_t vecComparisons;

		void									validateInput(int argc, char *argv[]);
		void									printContainer(int which, int when);
		std::vector<int>						sortByFordJohnsonVector(std::vector<int> sortVec);
		std::vector<int>						extractLargePairs(std::vector<std::pair<int, int>> pairVector);
		std::vector<int>						insertOrder(std::vector<int> nextLevel, std::vector<std::pair<int, int>> pairVector);
		std::deque<int>							sortByFordJohnsonDeque(std::deque<int> sortDeq);
		std::deque<int>							extractLargePairsDeq(std::deque<std::pair<int, int>> pairDeque);
		std::deque<int>							insertDeqOrder(std::deque<int> nextLevel, std::deque<std::pair<int, int>> pairDeque);
		std::vector<std::pair<int, int>>		reorderPairsBySortedWinnersVec(std::vector<std::pair<int, int>> pairVector, std::vector<int> sortedWinners);
		std::deque<std::pair<int, int>>			reorderPairsBySortedWinnersDeq(std::deque<std::pair<int, int>> pairDeque, std::deque<int> sortedWinners);

		template <typename J>
		J buildJacobsthalSequence(size_t n) {

			J jsOrder;

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

		template <typename J>
		J jacobsthalSpreadIndices(size_t n) {

			J completeJcIndecies;

			if (n == 0)
				return completeJcIndecies;

			completeJcIndecies.push_back(0);
			if (n == 1)
				return completeJcIndecies;

			J jacobsthalOrder = buildJacobsthalSequence<J>(n);

			for (size_t i = 1; i < jacobsthalOrder.size(); i ++) {

				size_t upper = jacobsthalOrder[i];
				size_t lower = jacobsthalOrder[i - 1];

				if (upper > n)
					upper = n;
				
				for (size_t idx = upper; idx > lower; idx--) {
					completeJcIndecies.push_back(idx - 1);
				}
			}

			return completeJcIndecies;
		};

	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char **argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

};

struct CountCompare {
	size_t *counter;

	CountCompare(size_t *c) : counter(c) {}

	bool operator()(int lhs, int rhs) const {
		++(*counter);
		return lhs < rhs;
	}
};

#endif