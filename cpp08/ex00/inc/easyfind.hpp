#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
auto easyFind(const T& container, int n) {
	auto it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}
