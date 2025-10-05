#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1() {
	std::cout << C_W << "\nBASIC TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	Bureaucrat timo("Timo", 72);
	Form a("A21212", 110, 90);
	try {
		std::cout << timo << std::endl;
		timo.signForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

// TODO: MORE TESTS!
int main() {
	test1();

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
