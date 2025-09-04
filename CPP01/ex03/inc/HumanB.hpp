#pragma once

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon* _weapon;
public:
	HumanB(const std::string& name);

	void setWeapon(Weapon& weapon);
	void attack();
};
