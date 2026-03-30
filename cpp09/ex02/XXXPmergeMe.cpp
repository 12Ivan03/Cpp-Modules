
#include "XXXPmergeMe.hpp"

// OCF

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq), _vecComparisons(other._vecComparisons) {};

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
		
	if (this != &other) {
		this->_vec = other._vec;
		this->_deq = other._deq;
		_vecComparisons = other._vecComparisons;
	}
	return *this;
};

PmergeMe::~PmergeMe() {};

// main logic

PmergeMe::PmergeMe(int argc, char *argv[]) : _vecComparisons(0) {

	validateInput(argc, argv);

	printContainer(1, 1);
	auto startVec = std::chrono::high_resolution_clock::now();
	_vec = sortByFordJohnsonVector(_vec);
	auto stopVec = std::chrono::high_resolution_clock::now();
	double durationVec = std::chrono::duration<double>(stopVec - startVec).count();

	// auto startDeq = std::chrono::high_resolution_clock::now();
	// _deq = sortByFordJohnsonDeque(_deq);
	// auto stopDeq = std::chrono::high_resolution_clock::now();
	// double durationDeq = std::chrono::duration<double>(stopDeq - startDeq).count();
	printContainer(1, 2);

	std::cout << std::fixed << std::setprecision(6);
	std::cout  << "Time to process a range of " 
				<< _vec.size() 
				<< " elements with std::vector<int> : " 
				<< durationVec
				<< " us" << std::endl;
	// std::cout  << "Time to process a range of " 
	// 			<< _deq.size() << " elements with std::deque<int> : " 
	// 			<< durationDeq 
	// 			<< " us" 
	// 			<< std::endl;
	// std::cout << std::defaultfloat;

	std::cout << "Comparisons : " << _vecComparisons << std::endl;

};

//deque

std::deque<int>	PmergeMe::sortByFordJohnsonDeque(std::deque<int> deqInProgress) {

	if (deqInProgress.size() <= 1)
		return deqInProgress;

	std::deque<std::pair<int, int>> pairDeque;
	int oddDequeLength = -1;

	size_t i = 0;
	for (; i + 1 < deqInProgress.size(); i += 2) {

		int a = deqInProgress[i];
		int b = deqInProgress[i + 1];
		if (a >= b) {
			pairDeque.push_back(std::make_pair(a, b));
		} else {
			pairDeque.push_back(std::make_pair(b, a));
		}
	}

	if (i < deqInProgress.size())
		oddDequeLength = deqInProgress[i];

	std::deque<int> lList = extractLargePairDeq(pairDeque);
	std::deque<int> nextLevel = sortByFordJohnsonDeque(lList);
	
	deqInProgress = insertDeqOrder(nextLevel, pairDeque);

	if (oddDequeLength != -1) {
		std::deque<int>::iterator pos = std::lower_bound(deqInProgress.begin(), deqInProgress.end(), oddDequeLength);
		deqInProgress.insert(pos, oddDequeLength); 
	}
	return deqInProgress;
};

std::deque<int>		PmergeMe::extractLargePairDeq(std::deque<std::pair<int, int>> pairDeque) {

	std::deque<int> extrLargeNum;

	for (size_t i = 0; i < pairDeque.size(); i++) 
		extrLargeNum.push_back(pairDeque[i].first);
	return extrLargeNum;
};

std::deque<int>		PmergeMe::insertDeqOrder(std::deque<int> nextLevel, std::deque<std::pair<int, int>> pairDeque) {

	std::deque<size_t> jacobOrder = jacobsthalIndices<std::deque<size_t>>(pairDeque.size());

	for (size_t i = 0; i < pairDeque.size(); i++) {

		size_t j = jacobOrder[i];

		int small = pairDeque[j].second;
		int big = pairDeque[j].first;

		std::deque<int>::iterator posBig = std::lower_bound(nextLevel.begin(), nextLevel.end(), big);
		std::deque<int>::iterator pos = std::lower_bound(nextLevel.begin(), posBig, small);

		nextLevel.insert(pos, small);

	}
	return nextLevel;
};

//vector

std::vector<std::pair<int, int> >	PmergeMe::reorderPairsBySortedWinners(
	std::vector<std::pair<int, int> > pairVector,
	std::vector<int> sortedWinners
) {

	std::vector<std::pair<int, int> > reordered;
	std::vector<bool> used(pairVector.size(), false);

	for (size_t i = 0; i < sortedWinners.size(); i++) {
		for (size_t j = 0; j < pairVector.size(); j++) {
			if (!used[j] && pairVector[j].first == sortedWinners[i]) {
				reordered.push_back(pairVector[j]);
				used[j] = true;
				break;
			}
		}
	}
	return reordered;
};

std::vector<int>	PmergeMe::sortByFordJohnsonVector(std::vector<int> vecInProgress) {

	if (vecInProgress.size() <= 1)
		return vecInProgress;

	std::vector<std::pair<int, int>> pairVector;
	int		oddVec = -1;
	int		oddPartner = -1;

	size_t i = 0;
	for (; i + 1 < vecInProgress.size(); i += 2) {
		int a = vecInProgress[i];
		int b = vecInProgress[i + 1];
		++_vecComparisons;
		if (a >= b)
			pairVector.push_back(std::make_pair(a, b));
		else
			pairVector.push_back(std::make_pair(b, a));
	}

	if (i < vecInProgress.size()) {
		oddVec = vecInProgress[i];
		oddPartner = pairVector.back().first;
	}

	std::cout << "oddVec: " << oddVec << " oddPartner: " << oddPartner << std::endl;

	std::vector<int> lList = extractLargePairs(pairVector);
	std::vector<int> nextLevel = sortByFordJohnsonVector(lList);

	pairVector = reorderPairsBySortedWinners(pairVector, nextLevel);

	vecInProgress = insertOrder(nextLevel, pairVector);

	if (oddVec != -1) {

		size_t partnerIdx = 0;
		while (partnerIdx < vecInProgress.size() && vecInProgress[partnerIdx] != oddPartner)
			partnerIdx++;
		auto pos = std::lower_bound(vecInProgress.begin(), vecInProgress.begin() + partnerIdx, oddVec, CountCompare(&_vecComparisons));
		vecInProgress.insert(pos, oddVec);


		// std::vector<int>::iterator pos = std::lower_bound(
		// 	vecInProgress.begin(), 
		// 	vecInProgress.end(), 
		// 	oddVec, 
		// 	CountCompare(&_vecComparisons)
		// );
		// vecInProgress.insert(pos, oddVec);
	}

	return vecInProgress;
};

std::vector<int>	PmergeMe::insertOrder(std::vector<int> nextLevel, std::vector<std::pair<int, int>> pairVector) {
		
	// std::cout << " C jacobsthalIndices ->pairVector.size():  "<< pairVector.size() << std::endl;

	std::vector<int> mainChain;
	std::vector<size_t> bigPos; 

	if (pairVector.empty())
		return nextLevel;

	mainChain.push_back(pairVector[0].second);

	for (size_t i = 0; i < nextLevel.size(); i++)
		mainChain.push_back(nextLevel[i]);

	for (size_t i = 0; i < pairVector.size(); i++) {
		bigPos.push_back(i + 1);
	}

	// {
	// 	std::cout << "bigPos:";
	// 	for (size_t i = 0; i < bigPos.size(); i++)
	// 		std::cout << " " << bigPos[i]; 
	// 	std::cout << std::endl; 
	// }

	std::vector<size_t> JacobOrder = jacobsthalIndices<std::vector<size_t>>(pairVector.size());

	for (size_t i = 0; i < JacobOrder.size(); i++) {

		size_t j = JacobOrder[i];
		// std::cout << "JacobOrder = " << j << std::endl; 
		if (j == 0)
			continue;

		int small = pairVector[j].second;
		// int big = pairVector[j].first;

		size_t bound = bigPos[j]; 
		// bigPos[JacobsthalIndex] -> gives us the position of the winner in the mainChain.
		// std::cout << "bound = " << bound << std::endl; 
		//  The bigPos indexses coresponds to the mainChain ordered numbers and when jacomsphal tell us , you need to insert 4 aka 4th pair. that is becomes the index in the bigPos[JacobOrder[i]]. so that gives us where the winner sits in the mainChain. becuase the main chain is ordered and we are dealing with that winner and its loser?
		// std::vector<int>::iterator posBig = std::lower_bound(mainChain.begin(), mainChain.end(), big);
		std::vector<int>::iterator pos = std::lower_bound(
			mainChain.begin(),
			mainChain.begin() + bound,
			small,
			CountCompare(&_vecComparisons)
		);

		size_t insertIdx = pos - mainChain.begin();
		// insertIdx is the position where the loser goes, and also the point from which all later elements shift right.
		// std::cout << "insertIdx = pos - mainChain.begin(); = " << insertIdx << std::endl; 

		mainChain.insert(pos, small);
		
		for (size_t k = 0; k < bigPos.size(); k++) {
			if (bigPos[k] >= insertIdx)
				bigPos[k]++;
		}
	}

	return mainChain;
};

std::vector<int>	PmergeMe::extractLargePairs(std::vector<std::pair<int, int>> pairVector) {

	std::vector<int> extrLarge;

	for (size_t i = 0; i < pairVector.size(); i++)
		extrLarge.push_back(pairVector[i].first);
	return extrLarge;
};

void	PmergeMe::validateInput(int argc, char *argv[]) {

	if (argc <= 1)
		throw std::runtime_error("correct input: ./Program \' shuf -i LO-HI -n N || jot -r 1 $min $max \'");
		
	for (int i = 1; i < argc; i++) {

		std::istringstream argvString(argv[i]);
		std::string s;

		while (argvString >> s) {
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
	}
};

// printng
void	PmergeMe::printContainer(int n, int when) {

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
