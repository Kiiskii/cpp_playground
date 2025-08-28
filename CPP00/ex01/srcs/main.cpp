#include "../inc/PhoneBook.hpp"

int main(void) {
	PhoneBook book;
	std::string command;
	int id = 0;

	std::cout << "You have opened the Phonebook!" << std::endl;
	while (true) {
		std::cout << std::endl;
		std::cout << "You can ADD, SEARCH or EXIT" << std::endl;
		std::cout << "Enter a command: ";
		safeGetLine(command);
		std::cout << std::endl;

		if (command == "ADD") {
			book.addContact(id);
			if (id == 7)
				id = 0;
			else
				id++;
		}
		else if (command == "SEARCH")
			book.displayAll();
		else if (command == "EXIT") {
			std::cout << std::endl;
			std::cout << "You have closed the Phonebook... Goodbye!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return 0;
}
