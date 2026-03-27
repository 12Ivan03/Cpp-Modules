
#include "PmergeMe.hpp"


// OCF
// PmergeMe::PmergeMe() {};

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

	auto startDeq = std::chrono::high_resolution_clock::now();
	_deq = sortByFordJohnsonDeque(_deq);
	auto stopDeq = std::chrono::high_resolution_clock::now();
	double durationDeq = std::chrono::duration<double>(stopDeq - startDeq).count();
	printContainer(2, 2);

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

std::vector<int>	PmergeMe::sortByFordJohnsonVector(std::vector<int> vecInProgress) {

	if (vecInProgress.size() <= 1)
		return vecInProgress;

	std::vector<std::pair<int, int>> pairVector;
	int		oddVecLenght = -1;
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
		oddVecLenght = vecInProgress[i];
		oddPartner = pairVector.back().first;
	}

	std::cout << "oddVecLenght: " << oddVecLenght << " oddPartner: " << oddPartner << std::endl;

	std::vector<int> lList = extractLargePairs(pairVector);
	std::vector<int> nextLevel = sortByFordJohnsonVector(lList);

	vecInProgress = insertOrder(nextLevel, pairVector);

	if (oddVecLenght != -1) {
 		// size_t partnerIdx = indexMap[oddPartner]; // free lookup, no comparisons, no lower_bound
		// auto pos = std::lower_bound(vecInProgress.begin(), vecInProgress.begin() + partnerIdx, oddVecLenght, CountCompare(&_vecComparisons));
		// vecInProgress.insert(pos, oddVecLenght);
		
		// std::vector<int>::iterator partnerPos = std::lower_bound(vecInProgress.begin(), vecInProgress.end(), oddPartner);
        // std::vector<int>::iterator pos = std::lower_bound(vecInProgress.begin(), partnerPos, oddVecLenght, CountCompare(&_vecComparisons));
        // vecInProgress.insert(pos, oddVecLenght);

		std::vector<int>::iterator pos = std::lower_bound(vecInProgress.begin(), vecInProgress.end(), oddVecLenght,CountCompare(&_vecComparisons));
		vecInProgress.insert(pos, oddVecLenght);
	}

	return vecInProgress;
};

std::vector<int>	PmergeMe::insertOrder(std::vector<int> nextLevel, std::vector<std::pair<int, int>> pairVector) {
		
	// std::cout << " C jacobsthalIndices ->pairVector.size():  "<< pairVector.size() << std::endl;

	std::vector<size_t> JacobOrder = jacobsthalIndices<std::vector<size_t>>(pairVector.size());

	std::unordered_map<int, size_t> bigIndex;
    for (size_t i = 0; i < nextLevel.size(); i++)
        bigIndex[nextLevel[i]] = i;

    for (size_t i = 0; i < pairVector.size(); i++) {

        size_t j = JacobOrder[i];

        int small = pairVector[j].second;
        int big   = pairVector[j].first;

        size_t bigIdx = bigIndex[big];

        // If big is at index 0, small must be smaller than everything, insert at front
        if (bigIdx == 0) {
            nextLevel.insert(nextLevel.begin(), small);
            for (auto& entry : bigIndex)
                entry.second++;
        } else {
            auto pos = std::lower_bound(nextLevel.begin(), nextLevel.begin() + bigIdx, small, CountCompare(&_vecComparisons));
            size_t insertIdx = pos - nextLevel.begin();
            nextLevel.insert(pos, small);
            for (auto& entry : bigIndex)
                if (entry.second >= insertIdx)
                    entry.second++;
        }
    }
    return nextLevel;

	// for (size_t i = 0; i < pairVector.size(); i++) {
		
	// 	size_t j = JacobOrder[i];

	// 	int small = pairVector[j].second;
	// 	int big = pairVector[j].first;

	// 	std::vector<int>::iterator posBig = std::lower_bound(nextLevel.begin(), nextLevel.end(), big);
	// 	std::vector<int>::iterator pos = std::lower_bound(nextLevel.begin(), posBig, small, CountCompare(&_vecComparisons));

	// 	nextLevel.insert(pos, small);
	// }
	// return nextLevel;
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
