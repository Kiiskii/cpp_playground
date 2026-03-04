#include "../inc/RPN.hpp"
#include <cctype>
#include <climits>
#include <sstream>
#include <stdexcept>

void RPN::applyOperator(char op) {
	if (_stack.size() < 2)
		throw std::runtime_error("not enough operands");
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();
	long res = 0;

	switch (op) {
	case '+':
		res = static_cast<long>(left) + static_cast<long>(right);
		break ;
	case '-':
		res = static_cast<long>(left) - static_cast<long>(right);
		break ;
	case '*':
		res = static_cast<long>(left) * static_cast<long>(right);
		break ;
	case '/':
		if (right == 0)
			throw std::runtime_error("cannot divide by 0");
		res = static_cast<long>(left) / static_cast<long>(right);
		break ;
	}
	if (res > INT_MAX || res < INT_MIN)
		throw std::runtime_error("integer overflow or underflow");
	_stack.push(res);
}

void RPN::execute(std::string& expression) {
	std::istringstream ss(expression);
	std::string token;
	while (ss >> token) {
		if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
			applyOperator(token[0]);
		else if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else
			throw std::runtime_error("invalid token: " + token);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("invalid expression");
	std::cout << C_G << "result: " << _stack.top() << C_RST << std::endl;
}
