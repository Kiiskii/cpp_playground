#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	//std::cout << "Dog default constructor called." << std::endl;
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Dog brain, memory allocation failed: " << e.what() << std::endl;
		_brain = nullptr;
	}
}

Dog::Dog(const Dog& other) : Animal(other) {
	//std::cout << "Dog copy constructor called." << std::endl;
	try {
		_brain = new Brain(*other._brain);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Dog brain, memory allocation failed: " << e.what() << std::endl;
		_brain = nullptr;
	}
}

Dog& Dog::operator=(const Dog& other) {
	//std::cout << "Dog assignment operator called." << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		try {
			_brain = new Brain(*other._brain);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Dog brain, memory allocation failed: " << e.what() << std::endl;
			_brain = nullptr;
		}
	}
	return *this;
}

Dog::~Dog() {
	//std::cout << "Dog destructor called." << std::endl;
	if (_brain)
		delete _brain;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF" << std::endl;
}

void Dog::setIdea(int i, const std::string& str) {
	if (_brain) {
		std::cout << "Dog got a new idea!" << std::endl;
		_brain->setIdea(i, str);
	}
	else
		std::cerr << "No memory allocated for brain to set idea." << std::endl;
}

const std::string& Dog::getIdea(int i) const {
	if (_brain)
		return _brain->getIdea(i);
	static const std::string empty = "";
	std::cerr << "No memory allocated to get idea." << std::endl;
	return empty;
}
