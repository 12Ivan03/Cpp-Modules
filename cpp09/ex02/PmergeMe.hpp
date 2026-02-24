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
		std::deque<int>		sortByFordJohnsonDeque();
		std::vector<int>	extractLargePairs(std::vector<std::pair<int, int>> pairVector);
		std::vector<int>	insertOrder(std::vector<int> nextLevel, std::vector<std::pair<int, int>> pairVector);

	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		
};

#endif