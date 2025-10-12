#pragma once

#include <iostream>
#include <string>

#define C_G		"\033[0;32m\001"
#define C_R		"\033[0;31m\001"
#define C_RST	"\033[0m\002"

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter {
private:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter& operator=(const ScalarConverter& other) = delete;
	~ScalarConverter() = delete;
public:
	static void convert(const std::string& num);
};
