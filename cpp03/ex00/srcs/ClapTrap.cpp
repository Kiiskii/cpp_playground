#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_name = "Unnamed";
	_health = 10;
	_energy = 10;
	_atkDmg = 0;

	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name) {
	_health = 10;
	_energy = 10;
	_atkDmg = 0;

	std::cout << "ClapTrap (" << _name << ") constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object) {
	this->_name = object._name;
	this->_health = object._health;
	this->_energy = object._energy;
	this->_atkDmg = object._atkDmg;

	std::cout << "ClapTrap (" << _name << ") copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& object) {
	if (this != &object) {
		this->_name = object._name;
		this->_health = object._health;
		this->_energy = object._energy;
		this->_atkDmg = object._atkDmg;
	}
	std::cout << "ClapTrap (" << _name << ") assignment operator called." << std::endl;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap (" << _name << ") destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy == 0) {
		std::cout << "ClapTrap (" << _name << ") doesn't have energy left to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap (" << _name << ") attacks, causing " << _atkDmg << " damage to " << target << "!" << std::endl;
	_energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_health == 0) {
		std::cout << "ClapTrap (" << _name << ") is already dead." << std::endl;
		return ;
	}
	_health = _health - amount;
	std::cout << "ClapTrap (" << _name << ") took " << amount << " points of damage." << std::endl;
	if (_health <= 0) {
		_health = 0;
		std::cout << _name << " has died." << std::endl;
		return ;
	}
	std::cout << "Current health: " << _health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy == 0 && _health > 0) {
		std::cout << "ClapTrap (" << _name << ") doesn't have enough energy to repair itself." << std::endl;
		return ;
	}
	if (_health <= 0) {
		std::cout << "Dead things cannot repair themselves." << std::endl;
		return ;
	}
	_health += amount;
	_energy--;
	std::cout << "ClapTrap (" << _name << ") repaired itself for " << amount << " health.\n";
	std::cout << "Current health: " << _health << std::endl;
}
