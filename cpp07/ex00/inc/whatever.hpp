#pragma once

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
# define C_RST	"\033[0m\002"

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T& a, T& b) {
	return (a < b) ? a : b;
}

template <typename T>
T& max(T& a, T& b) {
	return (a > b) ? a : b;
}
