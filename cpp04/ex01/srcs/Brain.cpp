#include "Brain.hpp"

Brain::Brain() {
	std::string ideas_list[3]{"I want to eat", "I want to sleep", "I want to play"};

	for (int i = 0; i < IDEAS_AMOUNT; i++)
		_ideas[i] = ideas_list[i % 3];

	//std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < IDEAS_AMOUNT; i++)
		_ideas[i] = other._ideas[i];

	  //std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < IDEAS_AMOUNT; i++)
			_ideas[i] = other._ideas[i];
	}

	//std::cout << "Brain assignment operator called." << std::endl;
	return *this;
}

Brain::~Brain() {
	//std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdea(int i, const std::string& str) {
	if (i >= 0 && i < IDEAS_AMOUNT)
		_ideas[i] = str;
	else
		std::cout << i << " is out of range for brain." << std::endl;
}

const std::string& Brain::getIdea(int i) const {
	if (i >= 0 && i < IDEAS_AMOUNT)
		return _ideas[i];
	else {
		static const std::string error = "index is out of range.";
		return error;
	}
}
