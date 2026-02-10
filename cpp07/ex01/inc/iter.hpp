#pragma once
#include <iostream>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

template <typename T, typename F>
void iter(T* arr, size_t len, F func) {
	if (!arr || !len)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}
