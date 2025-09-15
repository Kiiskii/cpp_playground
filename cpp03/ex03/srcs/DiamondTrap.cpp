#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	ClapTrap::_health = FragTrap::defaultHealth;
	ClapTrap::_energy = ScavTrap::defaultEnergy;
	ClapTrap::_atkDmg = FragTrap::defaultDmg;

	std::cout << "DiamondTrap (" << _name << ") default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name + "_clap_name"),
		FragTrap(name + "_clap_name"),
		ScavTrap(name + "_clap_name") {
	_name = name;
	ClapTrap::_health = FragTrap::defaultHealth;
	ClapTrap::_energy = ScavTrap::defaultEnergy;
	ClapTrap::_atkDmg = FragTrap::defaultDmg;

	std::cout << "DiamondTrap (" << _name << ") constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& object)
	: ClapTrap(object), FragTrap(object), ScavTrap(object), _name(object._name) {
	std::cout << "DiamondTrap (" << _name << ") copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& object) {
	if (this != &object) {
		ClapTrap::operator=(object);
		FragTrap::operator=(object);
		ScavTrap::operator=(object);
		_name = object._name;
	}
	std::cout << "DiamondTrap (" << _name << ") assignment operator called." << std::endl;

	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap (" << _name << ") destructor called." << std::endl;
}

void DiamondTrap::whoAmI() {
	if (_health > 0) {
		std::cout	<< "My DiamondTrap name is " << _name << " and my ClapTrap name is "
					<< ClapTrap::_name << "." << std::endl;
	}
	else
		std::cout << "DiamondTrap is dead." << std::endl;
}
