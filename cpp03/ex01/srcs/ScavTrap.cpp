#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_health = 100;
	_energy = 50;
	_atkDmg = 20;

	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_health = 100;
	_energy = 50;
	_atkDmg = 20;

	std::cout << "ScavTrap (" << _name << ") constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& object) {
	this->_name = object._name;
	this->_health = object._health;
	this->_energy = object._energy;
	this->_atkDmg = object._atkDmg;

	std::cout << "ScavTrap (" << _name << ") copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object) {
	if (this != &object) {
		this->_name = object._name;
		this->_health = object._health;
		this->_energy = object._energy;
		this->_atkDmg = object._atkDmg;
	}
	std::cout << "ScavTrap (" << _name << ") assignment operator called." << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap (" << _name << ") destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energy == 0) {
		std::cout << "ScavTrap (" << _name << ") doesn't have energy left to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap (" << _name << ") attacks, causing " << _atkDmg << " damage to " << target << "!" << std::endl;
	_energy--;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap (" << _name << ") ";
	if (_health > 0)
		std::cout << "is in gatekeeper mode." << std::endl;
	else
		std::cout << "cannot go into gatekeeper mode, because it is dead." << std::endl;
}
