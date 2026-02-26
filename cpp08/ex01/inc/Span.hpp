#pragma once
#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
private:
	unsigned int _capacity;
	std::vector<int> _arr;
public:
	Span() = delete;
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int nbr);
	int shortestSpan() const;
	int longestSpan() const;

	template<typename Input>
	void addNumber(Input begin, Input end) {
		auto dist = std::distance(begin, end);
		if (dist < 0 || _arr.size() + static_cast<unsigned int>(dist) > _capacity)
			throw std::overflow_error("Array full");
		_arr.insert(_arr.end(), begin, end);
	}
};
