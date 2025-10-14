#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << C_R << "error: usage: ./ScalarConverter [value]" << C_RST << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));

	return 0;
}
