#pragma once

#include <stack>
#include <iostream>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

class RPN {
private:
	std::stack<int> _stack;
public:
	RPN() = default;
	RPN(const RPN& other) = delete;
	RPN& operator=(const RPN& other) = delete;
	~RPN() = default;

	void execute(std::string& expression);
	void applyOperator(char op);
};
