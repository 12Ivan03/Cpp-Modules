
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

class PmergeMe {

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

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

#endif
// ex02 
//	1. std::vector<int> 
//	2. std::deque<int>

// PmergeMe
//  	OCF
//		two owns containers -> _vec, _deq
//				exposes one public “run” style function that does everything
// 				least 3000 different integers.

// Flow describtion
// 	One top-level function does:

// 		Parse & validate argv
//				all are positive integers
// 				error -> print "Error" to std::cerr and exit/throw
// 						Duplicate numbers: Decision to be taken: 	
// 								Option A (common/easy): treat duplicates as an error → print Error to std::cerr and stop (don’t sort).
// 								Option B: allow duplicates → sort normally (just make sure your algorithm handles equality safely).

//  	Print “Before:” using the original sequence (or container before sort)
//				Before:  3 5 9 7 4 

//  	Populate both containers
// 				_vec.assign(...)
// 				_deq.assign(...)

//  	Sort each container
// 				sortVectorFordJohnson(_vec)
// 				sortDequeFordJohnson(_deq)

//  	Print “After:” (use one container, they should match)
// 				After: 3 4 5 7 9

//  	Measure and print timings
// 				include everything: parsing + container fill + sorting + any extra steps you do for the algorithm (per subject)
// 				Time to process a range of 5 elements with std::[specifying the first container] : 0.00031 us
// 				Time to process a range of 5 elements with std::[specifying the second container] : 0.00014 us
// 

// 		~~~~~~~~~~~~~ Ford-Johnson ~~~~~~~~~~~~~
//		1. pair up elements
//		2. sort the “larger” elements (recursively) by pair again the L numbers
//		3. insert the smaller ones into the main chain using binary insertion in a specific order (often Jacobsthal-based insertion order)
// 			- from beginning to L position


// 		For each pair, you compare and order them so you know:
// 			small[i] <= large[i]
// Then you do:
// 		Recursively sort all large[i]
// 		That sorted list of large values becomes your main chain
// 		Then you insert the small[i] values into that main chain using binary insertion — but in a special order (Jacobsthal order) to minimize comparisons.


// 		~~~~~~~~~~~~~~~~~~~	DETAILED PSEVDO CODE: ~~~~~~~~~~~~~~~~~~~

// function fordJohnson(C):
//     if size(C) <= 1:
//         return C

//     pairs = empty list of (L, S)
//     straggler_exists = false

//     # 1) Pair up and compare inside each pair
//     i = 0
//     while i + 1 < size(C):
//         a = C[i]
//         b = C[i+1]
//         if a >= b:
//             pairs.push( (a, b) )   # L=a, S=b
//         else:
//             pairs.push( (b, a) )   # L=b, S=a
//         i = i + 2

//     # If odd count, keep the last element as straggler
//     if i < size(C):
//         straggler = C[i]
//         straggler_exists = true

//     # 2) Extract all L values and recursively sort them
//     Llist = [ each pair.L in pairs ]
//     main = fordJohnson(Llist)   # recursion

//     # 3) Insert the S values back into main (ORDER MATTERS if using Jacobsthal)
//     order = makeInsertionOrder(pairs.size())   # normal order or Jacobsthal order

//     for idx in order:
//         L = pairs[idx].L
//         S = pairs[idx].S
//         insertSmallBeforePartner(main, L, S)

//     # 4) Insert straggler if it exists
//     if straggler_exists:
//         insertIntoSorted(main, straggler)   # normal binary insert into full main

//     return main