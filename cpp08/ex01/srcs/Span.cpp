#include "../inc/Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span(unsigned int N) {
	_capacity = N;
	_arr.reserve(_capacity);
}

Span::Span(const Span& other) {
	_capacity = other._capacity;
	_arr = other._arr;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_capacity = other._capacity;
		_arr = other._arr;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
	if (_arr.size() >= _capacity)
		throw std::runtime_error("Array full");
	_arr.push_back(nb);
}

int Span::longestSpan() const {
	if (_arr.size() < 2)
		throw std::runtime_error("Not enough values to calculate span");

	std::vector<int> sortedArr = _arr;
	std::sort(sortedArr.begin(), sortedArr.end());
	return (sortedArr.back() - sortedArr.front());
}

int Span::shortestSpan() const {
	if (_arr.size() < 2)
		throw std::runtime_error("Not enough values to calculate span");

	std::vector<int> sortedArr = _arr;
	std::sort(sortedArr.begin(), sortedArr.end());
	std::vector<int> dif(sortedArr.size());
	std::adjacent_difference(sortedArr.begin(), sortedArr.end(), dif.begin());
	auto it = std::min_element(dif.begin() + 1, dif.end());
	return *it;
}
