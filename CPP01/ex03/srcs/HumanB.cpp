#include "../inc/HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(nullptr) {
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack" << std::endl;
}
