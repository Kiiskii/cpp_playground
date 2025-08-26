#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

// represents a single persons information
class Contact {
public:
	Contact(); // default constructor: creates an "empty contact"
	
	// setters: write values into objects
	void setFirstName(const std::string &firstname);
	void setLastName(const std::string &lastname);
	void setPhoneNumber(const std::string &phonenumber);

	// getters: read values from objects
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getPhoneNumber() const;

	// helper functions
	void displayContacts() const;

private:
	// private member variables: only accessible from inside the class
	std::string _firstName;
	std::string _lastName;
	std::string _phoneNumber;
};

#endif
