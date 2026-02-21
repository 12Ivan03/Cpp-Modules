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


//		1. pair up elements
//		2. sort the “larger” elements (recursively)
//		3. insert the smaller ones into the main chain using binary insertion in a specific order (often Jacobsthal-based insertion order)


// 		For each pair, you compare and order them so you know:
// 			small[i] <= large[i]
// Then you do:
// 		Recursively sort all large[i]
// 		That sorted list of large values becomes your main chain
// 		Then you insert the small[i] values into that main chain using binary insertion — but in a special order (Jacobsthal order) to minimize comparisons.

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <sstream>

class PmergeMe {

	private:
		std::vector<std::pair<int, int>> _vec;
		std::deque<std::pair<int, int>> _deq;

	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		
};

#endif