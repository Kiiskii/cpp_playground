#include "../inc/PhoneBook.hpp"

Contact::Contact() {
	_firstName = "_default";
	_lastName = "_default";
	_phoneNumber = "_default";
}

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

void Contact::setFirstName(const std::string &firstName) {
	_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	_lastName = lastName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	_phoneNumber = phoneNumber;
}
