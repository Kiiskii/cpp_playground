#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	//std::cout << "Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	//std::cout << "Animal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	//std::cout << "Animal copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	//std::cout << "Animal assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AAnimal::~AAnimal() {
	//std::cout << "Animal destructor called." << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}
