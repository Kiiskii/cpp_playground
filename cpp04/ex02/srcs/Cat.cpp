#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	//std::cout << "Cat default constructor called." << std::endl;
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Cat brain, memory allocation failed: " << e.what() << std::endl;
		_brain = nullptr;
	}
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	//std::cout << "Cat copy constructor called." << std::endl;
	try {
		_brain = new Brain(*other._brain);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Cat brain, memory allocation failed: " << e.what() << std::endl;
		_brain = nullptr;
	}
}

Cat& Cat::operator=(const Cat& other) {
	//std::cout << "Cat assignment operator called." << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		if (_brain)
			delete _brain;
		try {
			_brain = new Brain(*other._brain);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Cat brain, memory allocation failed: " << e.what() << std::endl;
			_brain = nullptr;
		}
	}
	return *this;
}

Cat::~Cat() {
	//std::cout << "Cat destructor called." << std::endl;
	if (_brain)
		delete _brain;
}

void Cat::makeSound() const {
	std::cout << "MEOW MEOW" << std::endl;
}

void Cat::setIdea(int i, const std::string& str) {
	if (_brain) {
		std::cout << "Cat got a new idea!" << std::endl;
		_brain->setIdea(i, str);
	}
	else
		std::cerr << "No memory allocated for brain to set idea." << std::endl;
}

const std::string& Cat::getIdea(int i) const {
	if (_brain)
		return _brain->getIdea(i);
	static const std::string empty = "";
	std::cerr << "No memory allocated to get idea." << std::endl;
	return empty;
}
