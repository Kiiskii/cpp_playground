#include "../inc/PhoneBook.hpp"

Contact::Contact() {
	_firstName = "_default";
	_lastName = "_default";
	_phoneNumber = "_default";
	_nickname = "_default";
	_secret = "_default";
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

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getSecret() const {
	return _secret;
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

void Contact::setNickname(const std::string &nickname) {
	_nickname = nickname;
}

void Contact::setSecret(const std::string &secret) {
	_secret = secret;
}
