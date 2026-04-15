#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <utility>
#include <deque>
#include <vector>

void PmergeMe::parseInput(int ac, char** av ) {
	if (ac < 2) {
		throw std::runtime_error("usage: PmergeMe <values>");
		return ;
	}
	for (int i = 1; i < ac; ++i) {
		size_t pos;
		int value = std::stoi(av[i], &pos);
		if (pos != std::string(av[i]).length()) {
			throw std::runtime_error("error: invalid input");
		}
		if (value < 0) {
			throw std::runtime_error("error: only positive values");
		}
		_vec.push_back(value);
		_deq.push_back(value);
	}
}

std::vector<int> PmergeMe::fordJohnVec(std::vector<int> vec) {
	if (vec.size() <= 1)
		return vec;

	int odd = -1;
	if (vec.size() % 2 != 0)
		odd = vec.back();

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		int winner = vec[i] > vec[i + 1] ? vec[i] : vec[i + 1];
		int loser = vec[i] > vec[i + 1] ? vec[i + 1] : vec[i];
		pairs.push_back({winner, loser});
	}
	std::vector<int> winners;
	for (auto& p : pairs)
		winners.push_back(p.first);
	winners = fordJohnVec(winners);

	std::vector<std::pair<int, int>> sortedPairs;
	std::vector<bool> used(pairs.size(), false);
	for (auto& w : winners) {
		for (size_t i = 0; i < pairs.size(); i++) {
			if (!used[i] && pairs[i].first == w) {
				sortedPairs.push_back(pairs[i]);
				used[i] = true;
				break ;
			}
		}
	}
	pairs = sortedPairs;

	std::vector<int> finalVec;
	for (auto& p : pairs)
		finalVec.push_back(p.first);

	std::vector<int> insertOrder = getJacobsthalOrder(pairs.size());
	for (int idx : insertOrder) {
		auto it = std::lower_bound(finalVec.begin(), finalVec.end(), pairs[idx].second);
		finalVec.insert(it, pairs[idx].second);
	}

	if (odd != -1) {
		auto it = std::lower_bound(finalVec.begin(), finalVec.end(), odd);
		finalVec.insert(it, odd);
	}

	return finalVec;
}

std::vector<int> PmergeMe::getJacobsthalOrder(int n) {
	std::vector<int> order;
	if (n == 0)
		return order;
	order.push_back(0);

	std::vector<int> jacob = {0, 1};
	while (jacob.back() < n)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	int prev = 1;
	for (size_t i = 2; i < jacob.size(); i++) {
		int curr = std::min(jacob[i], n);
		for (int j = curr; j > prev; j--)
			order.push_back(j - 1);
		prev = curr;
	}
	return order;
}

void PmergeMe::sortVector() {
	_vec = fordJohnVec(_vec);
}

void PmergeMe::printVector() {
	for (const auto& it : _vec)
		std::cout << it << " ";
	std::cout << std::endl;
}

std::deque<int> PmergeMe::fordJohnDeq(std::deque<int> deq) {
	if (deq.size() <= 1)
		return deq;

	int odd = -1;
	if (deq.size() % 2 != 0)
		odd = deq.back();

	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		int winner = deq[i] > deq[i + 1] ? deq[i] : deq[i + 1];
		int loser = deq[i] > deq[i + 1] ? deq[i + 1] : deq[i];
		pairs.push_back({winner, loser});
	}
	std::deque<int> winners;
	for (auto& p : pairs)
		winners.push_back(p.first);
	winners = fordJohnDeq(winners);

	std::deque<std::pair<int, int>> sortedPairs;
	std::vector<bool> used(pairs.size(), false);
	for (auto& w : winners) {
		for (size_t i = 0; i < pairs.size(); i++) {
			if (!used[i] && pairs[i].first == w) {
				sortedPairs.push_back(pairs[i]);
				used[i] = true;
				break ;
			}
		}
	}
	pairs = sortedPairs;

	std::deque<int> finalDeq;
	for (auto& p : pairs)
		finalDeq.push_back(p.first);

	std::vector<int> insertOrder = getJacobsthalOrder(pairs.size());
	for (int idx : insertOrder) {
		auto it = std::lower_bound(finalDeq.begin(), finalDeq.end(), pairs[idx].second);
		finalDeq.insert(it, pairs[idx].second);
	}

	if (odd != -1) {
		auto it = std::lower_bound(finalDeq.begin(), finalDeq.end(), odd);
		finalDeq.insert(it, odd);
	}

	return finalDeq;
}

void PmergeMe::sortDeque() {
	_deq = fordJohnDeq(_deq);
}

void PmergeMe::printDeque() {
	for (const auto& it : _deq)
		std::cout << it << " ";
	std::cout << std::endl;
}
