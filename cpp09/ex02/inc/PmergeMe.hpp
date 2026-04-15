#pragma once

#include <deque>
#include <vector>
#include <iostream>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

class PmergeMe {
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe& other) = delete;
	PmergeMe& operator=(const PmergeMe& other) = delete;
	~PmergeMe() = default;

	void parseInput(int ac, char** av);
	void printVector();
	void sortVector();
	std::vector<int> fordJohnVec(std::vector<int> vec);
	std::deque<int> fordJohnDeq(std::deque<int> deq);
	std::vector<int> getJacobsthalOrder(int n);
	void sortDeque();
	void printDeque();
};
