#include "ScalarConverter.hpp"
#include <exception>

void printImpossible() {
	std::cout << C_R << "char: impossible" << C_RST << std::endl;
	std::cout << C_R << "int: impossible" << C_RST << std::endl;
	std::cout << C_R << "float: impossible" << C_RST << std::endl;
	std::cout << C_R << "double: impossible" << C_RST << std::endl;
}

bool isTypeChar(const std::string& num) {
	if (num.length() == 1 && !std::isdigit(num[0]))
		return true;
	return false;
}

bool isTypeInt(const std::string& num) {
	int i = 0;

	if (num[i] == '+' || num[i] == '-') {
		i++;
	}
	while (num[i]) {
		if (!std::isdigit(num[i]))
			return false;
		i++;
	}
	try {
		std::stoi(num);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	return true;
}

int findType(const std::string& num) {
	if (isTypeChar(num))
		return CHAR;
	if (isTypeInt(num))
		return INT;
	return INVALID;
}

void ScalarConverter::convert(const std::string& num) {
	if (num.empty()) {
		printImpossible();
		return ;
	}

	int type = findType(num);

	switch (type) {
		case 0:
			std::cout << "char: " << num << std::endl;
			return ;
		case 1:
			std::cout << "int: " << num << std::endl;
			return ;
		case 4:
			std::cout << "invalid" << std::endl;
	}
}
