#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_count = 0;
}

void PhoneBook::addContact(int id) {
	std::string input;

	std::cout << "First name: ";
	safeGetLine(input);
	input = trim(input);
	_contacts[id].setFirstName(input);

	std::cout << "Last name: ";
	safeGetLine(input);
	input = trim(input);
	_contacts[id].setLastName(input);

	std::cout << "Phone number: ";
	safeGetLine(input);
	input = trim(input);
	_contacts[id].setPhoneNumber(input);

	std::cout << "Nickname: ";
	safeGetLine(input);
	input = trim(input);
	_contacts[id].setNickname(input);

	std::cout << "What is their deepest secret >:) : ";
	safeGetLine(input);
	input = trim(input);
	_contacts[id].setSecret(input);

	if (_count != 8)
		_count++;
}

std::string PhoneBook::truncString(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayContacts() const {
	std::string input;

	std::cout	<< std::setw(10) << "index" << " | "
				<< std::setw(10) << "1st name" << " | "
				<< std::setw(10) << "last name" << " | "
				<< std::setw(10) << "phone num" << " | " << std::endl;
	for (int j = 0; j < 4; ++j)
		std::cout << "-------------";
	std::cout << std::endl;
	for (int i = 0; i < _count; i++) {
		if (_contacts[i].getFirstName() != "_default") {
			std::cout	<< std::setw(10) << i << " | "
						<< std::setw(10) << truncString(_contacts[i].getFirstName()) << " | "
						<< std::setw(10) << truncString(_contacts[i].getLastName()) << " | "
						<< std::setw(10) << truncString(_contacts[i].getPhoneNumber()) << " | "
						<< std::endl;
		}
	}
	std::cout << std::endl;
}

void PhoneBook::searchContact() const {
	std::string input;
	int idx;

	while (true) {
		size_t index;
		std::cout << "Insert index between (0 - " << _count - 1 << "): ";
		safeGetLine(input);
		input = trim(input);

		try {
			idx = std::stoi(input, &index);
		}
		catch (std::invalid_argument) {
			std::cout << "invalid index" << std::endl;
			continue ;
		}
		catch (std::out_of_range) {
			std::cout << "invalid index" << std::endl;
			continue ;
		}
		if (input.length() != index) {
			std::cout << "invalid index" << std::endl;
			continue ;
		}

		if (idx >= 0 && idx < _count) {
			std::cout << "First name: " << _contacts[idx].getFirstName()
			<< std::endl;
			std::cout << "Last name: " << _contacts[idx].getLastName()
			<< std::endl;
			std::cout << "Phone number: " << _contacts[idx].getPhoneNumber()
			<< std::endl;
			std::cout << "Nickname: " << _contacts[idx].getNickname()
			<< std::endl;
			std::cout << "Their deepes secret >:D : " << _contacts[idx].getSecret()
			<< std::endl;
			break ;
		}
		else {
			std::cout << "invalid index" << std::endl;
		}
	}
}

void PhoneBook::displayAll() const {
	if (_count <= 0) {
		std::cout << "Phonebook is empty, please ADD contacts to it first!" << std::endl;
		return ;
	}
	displayContacts();
	searchContact();
}
