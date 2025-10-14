#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>
#include <limits>
#include <cctype>
#include <stdexcept>

void printImpossible() {
	std::cout << C_R << "char: impossible" << C_RST << std::endl;
	std::cout << C_R << "int: impossible" << C_RST << std::endl;
	std::cout << C_R << "float: impossible" << C_RST << std::endl;
	std::cout << C_R << "double: impossible" << C_RST << std::endl;
}

bool isTypeChar(const std::string& num) {
	if (num.size() == 1 && !std::isdigit(num[0]))
		return true;
	return false;
}

bool isTypeInt(const std::string& num) {
	size_t i = 0;

	if (num[i] == '+' || num[i] == '-') {
		i++;
	}
	while (i < num.size()) {
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
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;
}

bool isTypeFloat(const std::string& num) {
	size_t i = 0;
	int perCount = 0;

	if (num[i] == '+' || num[i] == '-') {
		i++;
	}
	while (i < num.size() && (std::isdigit(num[i]) || num[i] == '.')) {
		if (num[i] == '.')
			perCount++;
		if (perCount > 1)
			return false;
		i++;
	}
	if (i != num.size() - 1 || num[i] != 'f')
		return false;
	try {
		std::stof(num);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;
}

bool isTypeDouble(const std::string& num) {
	size_t i = 0;
	int perCount = 0;

	if (num[i] == '+' || num[i] == '-') {
		i++;
	}
	while (i < num.size() && (std::isdigit(num[i]) || num[i] == '.')) {
		if (num[i] == '.')
			perCount++;
		if (perCount > 1)
			return false;
		i++;
	}
	if (i < num.length())
		return false;
	try {
		std::stod(num);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;
}

bool isTypePseudoFloat(const std::string& num) {
	return (num == "-inff" || num == "+inff" || num == "nanf");
}

bool isTypePseudoDouble(const std::string& num) {
	return (num == "-inf" || num == "+inf" || num == "nan");
}

void handleChar(const std::string& num) {
	char c = num[0];

	if (std::isprint(c))
		std::cout << C_G << "char: " << "'" << c << "'" << C_RST << std::endl;
	else
		std::cout << C_R << "char: Non displayable" << C_RST << std::endl;

	std::cout << C_G << "int: " << static_cast<int>(c) << C_RST << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << C_G << "float: " << static_cast<float>(c) << "f" << C_RST << std::endl;
	std::cout << C_G << "double: " << static_cast<double>(c) << C_RST << std::endl;
}

void convertToChar(const std::string& num) {
	double converted;

	try {
		converted = std::stod(num);
	}
	catch (...) {
		std::cout << C_R << "char: impossible" << C_RST << std::endl;
		return ;
	}
	if (std::isnan(converted) || std::isinf(converted) || converted < 0.0 || converted > 127.0) {
		std::cout << C_R << "char: impossible" << C_RST << std::endl;
		return ;
	}
	if (converted == 127.0 || converted < 32.0) {
		std::cout << C_R << "char: Non displayable" << C_RST << std::endl;
		return ;
	}
	std::cout << C_G << "char: '" << static_cast<char>(converted) << "'" << C_RST << std::endl;
}

void convertToInt(const std::string& num) {
	double converted;

	try {
		converted = std::stod(num);
	}
	catch (...) {
		std::cout << C_R << "int: impossible" << C_RST << std::endl;
		return ;
	}
	if (std::isnan(converted) || std::isinf(converted)) {
		std::cout << C_R << "int: impossible" << C_RST << std::endl;
		return ;
	}
	if (converted > std::numeric_limits<int>::max() || converted < std::numeric_limits<int>::min()) {
		std::cout << C_R << "int: impossible" << C_RST << std::endl;
		return ;
	}
	std::cout << C_G << "int: " << static_cast<int>(converted) << C_RST << std::endl;
}

void convertToFloat(const std::string& num, int prec) {
	if (prec > 6)
		prec = 6;
	try {
		float converted = std::stof(num);
		std::cout << C_G << "float: ";
		std::cout << std::fixed << std::setprecision(prec);
		std::cout << converted << "f" << C_RST << std::endl;
	}
	catch (...) {
		std::cout << C_R << "float: impossible" << C_RST << std::endl;
		return ;
	}
}

void convertToDouble(const std::string& num, int prec) {
	if (prec > 15)
		prec = 15;
	try {
		double converted = std::stod(num);
		std::cout << C_G << "double: ";
		std::cout << std::fixed << std::setprecision(prec);
		std::cout << converted << C_RST << std::endl;
	}
	catch (...) {
		std::cout << C_R << "double: impossible" << C_RST << std::endl;
		return ;
	}
}

void handlePseudos(const std::string& num) {
	if (num == "-inf" || num == "-inff") {
		std::cout << C_G << "float: -inff" << C_RST << std::endl;
		std::cout << C_G << "double: -inf" << C_RST << std::endl;
	}
	else if (num == "+inf" || num == "+inff") {
		std::cout << C_G << "float: +inff" << C_RST << std::endl;
		std::cout << C_G << "double: +inf" << C_RST << std::endl;
	}
	else if (num == "nan" || num == "nanf") {
		std::cout << C_G << "float: nanf" << C_RST << std::endl;
		std::cout << C_G << "double: nan" << C_RST << std::endl;
	}
	else
		std::cout << C_R << "System error" << C_RST << std::endl;
}

int countDecimalPlaces(const std::string& num) {
	size_t dot = num.find('.');

	if (dot == std::string::npos)
		return 1;

	int count = 0;
	for (size_t i = dot + 1; i < num.size(); ++i) {
		if (num[i] == 'f')
			break ;
		if (std::isdigit(num[i]))
			count++;
		else
			break ;
	}
	if (count == 0)
		return 1;
	return count;
}

int findType(const std::string& num) {
	if (isTypeChar(num))
		return CHAR;
	if (isTypeInt(num))
		return INT;
	if (isTypeFloat(num))
		return FLOAT;
	if (isTypeDouble(num))
		return DOUBLE;
	if (isTypePseudoFloat(num))
		return PSEUDOFLOAT;
	if (isTypePseudoDouble(num))
		return PSEUDODOUBLE;
	return INVALID;
}

void ScalarConverter::convert(const std::string& num) {
	if (num.empty()) {
		printImpossible();
		return ;
	}

	int type = findType(num);
	int prec = countDecimalPlaces(num);

	switch (type) {
		case CHAR:
			handleChar(num);
			break ;
		case INT:
			convertToChar(num);
			convertToInt(num);
			convertToFloat(num, prec);
			convertToDouble(num, prec);
			break ;
		case FLOAT:
			convertToChar(num);
			convertToInt(num);
			convertToFloat(num, prec);
			convertToDouble(num, prec);
			break ;
		case DOUBLE:
			convertToChar(num);
			convertToInt(num);
			convertToFloat(num, prec);
			convertToDouble(num, prec);
			break ;
		case PSEUDOFLOAT:
			convertToChar(num);
			convertToInt(num);
			handlePseudos(num);
			break ;
		case PSEUDODOUBLE:
			convertToChar(num);
			convertToInt(num);
			handlePseudos(num);
			break ;
		case INVALID:
			printImpossible();
			break ;
		default:
			std::cout << C_R << "System error" << C_RST << std::endl;
	}
}
