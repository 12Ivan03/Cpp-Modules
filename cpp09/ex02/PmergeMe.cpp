
#include "PmergeMe.hpp"

// OCF

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq), _vecComparisons(other._vecComparisons) {};

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {

	if (this != &other) {
		this->_vec = other._vec;
		this->_deq = other._deq;
		this->_vecComparisons = other._vecComparisons;
	}
	return *this;
};

PmergeMe::~PmergeMe() {};
 
PmergeMe::PmergeMe(int argc, char *argv[]) : _vecComparisons(0) {

	validateInput(argc, argv);

	printContainer(1, 1);
	auto startTimeVec = std::chrono::high_resolution_clock::now();
	_vec = sortByFordJohnsonVector(_vec);
	auto stopTimeVec = std::chrono::high_resolution_clock::now();
	double totalDurationTimeVec = std::chrono::duration<double, std::micro>(stopTimeVec - startTimeVec).count(); 

	auto startTimeDeq = std::chrono::high_resolution_clock::now();
	_deq = sortByFordJohnsonDeque(_deq);
	auto stopTimeDeq = std::chrono::high_resolution_clock::now();
	double totalDurationTimeDeq = std::chrono::duration<double, std::micro>(stopTimeDeq - startTimeDeq).count(); 
	printContainer(1, 2);

	printDurationTime(totalDurationTimeVec, totalDurationTimeDeq);

};

// Vector

std::vector<int>						PmergeMe::sortByFordJohnsonVector(std::vector<int> values) {

	if (values.size() <= 1)
		return values;

	std::vector<std::pair<int, int>> pairValuesVec;
	int oddValue = -1;

	size_t i = 0;
	for (; i + 1 < values.size(); i += 2) {
		int a = values[i];
		int b = values[i + 1];
		++_vecComparisons;
		if(a >= b)
			pairValuesVec.push_back(std::make_pair(a, b));
		else
			pairValuesVec.push_back(std::make_pair(b, a));
	}

	if (i < values.size()) {
		oddValue = values[i];
	}

	std::vector<int> winnersList = extractWinners(pairValuesVec);
	std::vector<int> mainChain = sortByFordJohnsonVector(winnersList);

	pairValuesVec = reorderPairsBySortedWinnersVec(pairValuesVec, mainChain);

	values = insertOrder(mainChain, pairValuesVec);

	if (oddValue != -1) {
		std::vector<int>::iterator pos = std::lower_bound(values.begin(), values.end(), oddValue, CountCompare(&_vecComparisons));
		values.insert(pos, oddValue);
	}

	return values;
};
	// int oddPartnerValue = -1;		
	// oddPartnerValue = pairValuesVec.back().first;
	// size_t partnerIdx = 0;
	// while (partnerIdx < values.size() && values[partnerIdx] != oddPartnerValue)
	// 	partnerIdx++;

std::vector<int>	PmergeMe::extractWinners(std::vector<std::pair<int, int>> pairValuesVec) {

	std::vector<int> winners;

	for (size_t i = 0; i < pairValuesVec.size(); i++) {
		winners.push_back(pairValuesVec[i].first);
	}
	return winners;
};

std::vector<int>	PmergeMe::insertOrder(std::vector<int> mainChain, std::vector<std::pair<int, int>> pairValuesVec) {

	std::vector<int> mChain;
	std::vector<size_t> bigPos;

	if (pairValuesVec.empty())
		return mainChain;

	mChain.push_back(pairValuesVec[0].second);

	for(size_t i = 0; i < mainChain.size(); i++) {
		mChain.push_back(mainChain[i]);
	}
	for (size_t i = 0; i < pairValuesVec.size(); i++) {
		bigPos.push_back(i + 1);
	}

	std::vector<size_t> jacobOrder = jacobsthalSpreadIndices<std::vector<size_t>>(pairValuesVec.size());

	for (size_t i = 0; i < jacobOrder.size(); i++) {

		size_t j = jacobOrder[i];
		if (j == 0)
			continue;

		int small = pairValuesVec[j].second;
		size_t bound = bigPos[j];

		std::vector<int>::iterator pos = std::lower_bound(mChain.begin(), mChain.begin() + bound, small, CountCompare(&_vecComparisons));

		size_t insertIndex = pos - mChain.begin();
		mChain.insert(pos, small);

		for (size_t k = 0; k < bigPos.size(); k++) {
			if (bigPos[k] >= insertIndex)
				bigPos[k]++;
		}
	}

	return mChain;
};

std::vector<std::pair<int, int>>		PmergeMe::reorderPairsBySortedWinnersVec(
	std::vector<std::pair<int, int>> pairValuesVec, 
	std::vector<int> mainChain
) {

	std::vector<std::pair<int, int>> reordered;
	std::vector<bool> used(pairValuesVec.size(), false);

	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairValuesVec.size(); j++) {
			if (!used[j] && pairValuesVec[j]. first == mainChain[i]) {
				reordered.push_back(pairValuesVec[j]);
				used[j] = true;
				break;
			}
		}
	}
	return reordered;
};

// Deque

std::deque<int>							PmergeMe::sortByFordJohnsonDeque(std::deque<int> values) {

	if (values.size() <= 1)
		return values;

	std::deque<std::pair<int, int>> pairValuesVec;
	int oddValue = -1;

	size_t i = 0;
	for (; i + 1 < values.size(); i += 2) {
		int a = values[i];
		int b = values[i + 1];
		if(a >= b)
			pairValuesVec.push_back(std::make_pair(a, b));
		else
			pairValuesVec.push_back(std::make_pair(b, a));
	}

	if (i < values.size()) {
		oddValue = values[i];
	}

	std::deque<int> winnersList = extractWinnersDeq(pairValuesVec);
	std::deque<int> mainChain = sortByFordJohnsonDeque(winnersList);

	pairValuesVec = reorderPairsBySortedWinnersDeq(pairValuesVec, mainChain);

	values = insertDeqOrder(mainChain, pairValuesVec);

	if (oddValue != -1) {
		std::deque<int>::iterator pos = std::lower_bound(values.begin(), values.end(), oddValue);
		values.insert(pos, oddValue);
	}

	return values;
};
// int oddPartnerValue = -1;
// oddPartnerValue = pairValuesVec.back().first;
// size_t partnerIdx = 0;
// while (partnerIdx < values.size() && values[partnerIdx] != oddPartnerValue)
// 	partnerIdx++;

std::deque<int>							PmergeMe::extractWinnersDeq(std::deque<std::pair<int, int>> pairValuesDeq) {

	std::deque<int> winners;

	for (size_t i = 0; i < pairValuesDeq.size(); i++) {
		winners.push_back(pairValuesDeq[i].first);
	}
	return winners;
};

std::deque<int>							PmergeMe::insertDeqOrder(std::deque<int> mainChain, std::deque<std::pair<int, int>> pairValuesDeq) {


	std::deque<int> mChain;
	std::deque<size_t> bigPos;

	if (pairValuesDeq.empty())
		return mainChain;

	mChain.push_back(pairValuesDeq[0].second);

	for(size_t i = 0; i < mainChain.size(); i++) {
		mChain.push_back(mainChain[i]);
	}
	for (size_t i = 0; i < pairValuesDeq.size(); i++) {
		bigPos.push_back(i + 1);
	}

	std::deque<size_t> jacobOrder = jacobsthalSpreadIndices<std::deque<size_t>>(pairValuesDeq.size());

	for (size_t i = 0; i < jacobOrder.size(); i++) {

		size_t j = jacobOrder[i];
		if (j == 0)
			continue;

		int small = pairValuesDeq[j].second;
		size_t bound = bigPos[j];

		std::deque<int>::iterator pos = std::lower_bound(mChain.begin(), mChain.begin() + bound, small);

		size_t insertIndex = pos - mChain.begin();
		mChain.insert(pos, small);

		for (size_t k = 0; k < bigPos.size(); k++) {
			if (bigPos[k] >= insertIndex)
				bigPos[k]++;
		}
	}

	return mChain;
};

std::deque<std::pair<int, int>>			PmergeMe::reorderPairsBySortedWinnersDeq(std::deque<std::pair<int, int>> pairValuesDeq, std::deque<int> mainChain) {

	std::deque<std::pair<int, int>> reordered;
	std::deque<bool> used(pairValuesDeq.size(), false);

	for (size_t i = 0; i < mainChain.size(); i++) {
		for (size_t j = 0; j < pairValuesDeq.size(); j++) {
			if (!used[j] && pairValuesDeq[j]. first == mainChain[i]) {
				reordered.push_back(pairValuesDeq[j]);
				used[j] = true;
				break;
			}
		}
	}
	return reordered;
};


// helper functions: validate, prints

void PmergeMe::validateInput(int argc, char *argv[]) {

	if (argc <= 1)
		throw std::runtime_error("correct input: ./Program \' shuf -i LO-HI -n N || jot -r 1 $min $max \'");

	for (int i = 1; i < argc; i++) {

		std::istringstream argumentStream(argv[i]);
		std::string token;

		while (argumentStream >> token) {
			std::istringstream iss(token);
			long long num = 0;
			iss >> num;

			if (!token.empty() && !std::isdigit(static_cast<unsigned char>(token[0])))
				throw std::runtime_error("incorrect input");
			if (iss.fail())
				throw std::runtime_error("incorrect input: iss fail");
			std::string leftover;
			if (iss >> leftover)
				throw std::runtime_error("incorrect input: only integers");
			if (num <= 0)
				throw std::runtime_error("only positive numbers");
			if (num > INT_MAX)
				throw std::runtime_error("int overflow");
			if (std::find(_vec.begin(), _vec.end(), static_cast<int>(num)) != _vec.end())
				throw std::runtime_error("duplicates not allowed");

			_vec.push_back(static_cast<int>(num));
			_deq.push_back(static_cast<int>(num));
			
		}
	}


};

// prints
void	PmergeMe::printContainer(int whichTemplate, int when) {

	if (when == 1)
		std::cout << "Before: ";
	else 
		std::cout << "After: ";
	if (whichTemplate == 1) {
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

void	PmergeMe::printDurationTime(double totalDurationTimeVec, double totalDurationTimeDeq) {

	std::cout << std::fixed << std::setprecision(6);

	std::cout << "Time to process a range of " 
				<< _vec.size()
				<< " elements with std::vector<int> : "
				<< totalDurationTimeVec
				<< " us" << std::endl;
	std::cout << "Time to process a range of " 
				<< _deq.size()
				<< " elements with std::deque<int> : "
				<< totalDurationTimeDeq
				<< " us" << std::endl;

	std::cout << std::defaultfloat;
};

// std::cout << "Comparisons : " << _vecComparisons << std::endl;
// PmergeMe::printContainer(2, 2);