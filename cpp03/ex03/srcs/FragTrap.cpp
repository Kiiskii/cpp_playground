#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_health = 100;
	_energy = 100;
	_atkDmg = 30;

	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_health = 100;
	_energy = 100;
	_atkDmg = 30;

	std::cout << "FragTrap (" << _name << ") constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& object) : ClapTrap(object) {
	std::cout << "FragTrap (" << _name << ") copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& object) {
	if (this != &object)
		ClapTrap::operator=(object);
	std::cout << "FragTrap (" << _name << ") assignment operator called." << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap (" << _name << ") destructor called." << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap (" << _name << ") ";
	if (_health > 0)
		std::cout << "requests the highest of fives!" << std::endl;
	else
		std::cout << "cannot high five due to its lack of life." << std::endl;
}
