#pragma once

#include <iostream>
#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual void makeSound() const = 0; // pure virtual

	std::string getType() const;
};
