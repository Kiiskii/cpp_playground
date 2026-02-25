#include "../inc/Span.hpp"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) {
	_size = N;
	_arr.reserve(_size);
}

Span::Span(const Span& other) {
	_size = other._size;
	_arr = other._arr;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		_arr = other._arr;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
	if (_arr.size() >= _size)
		throw std::runtime_error("Array maximum size reached");
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
	std::vector<int>::iterator it = std::min_element(dif.begin() + 1, dif.end());
	return *it;
}
