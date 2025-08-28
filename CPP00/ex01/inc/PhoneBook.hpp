#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(); // initializes the count to 0
	
	void addContact(int id);
	void displayAll() const;
	void displayContacts() const;
	void searchContact() const;

private:
	Contact _contacts[8];							// fixed-sized array of 8 Contact objects
	int		_count;									// int to keep track of how many objects have been added
	std::string truncString(std::string str) const;	// function to truncate string
};

void safeGetLine(std::string &input);

#endif
