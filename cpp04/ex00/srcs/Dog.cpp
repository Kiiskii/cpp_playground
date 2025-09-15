#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF" << std::endl;
}
