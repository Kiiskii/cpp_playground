#include "../inc/PhoneBook.hpp"

void safeGetLine(std::string &input) {
	while (true) {
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof())
				std::cout << "\nEOF detected, closing phonebook." << std::endl;
			else {
				std::cout << "\n inputn error, closing phonebook." << std::endl;
			}
			std::cin.clear();
			exit(1);
		}
		bool empty_input = true;
		for (char c : input) {
			if (!std::isspace(static_cast<unsigned char>(c))) {
				empty_input = false;
				break ;
			}
		}
		if (!empty_input)
			break ;
		std::cout << "input cannot be empty.";
	}
}
