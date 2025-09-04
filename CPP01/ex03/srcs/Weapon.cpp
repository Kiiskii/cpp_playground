#include "../inc/Weapon.hpp"

Weapon::Weapon() {
	_type = "None";
}

Weapon::Weapon(const std::string& type) {
	_type = type;
}

void Weapon::setType(const std::string& type) {
	_type = type;
}

const std::string& Weapon::getType() const {
	return _type;
}
