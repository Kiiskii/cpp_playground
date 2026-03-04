#include "../inc/RPN.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "usage: ./RPN <reverse polish notation" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		std::string expr = av[1];
		rpn.execute(expr);
	} catch (const std::exception& e) {
		std::cerr << C_R << e.what() << C_RST << std::endl;
		return 1;
	}
	return 0;
}
