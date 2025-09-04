#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack" << std::endl;
}
