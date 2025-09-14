#pragma once

#include <iostream>
#include <string>

class ClapTrap {
private:
	std::string _name;
	int _health;
	int _energy;
	int _atkDmg;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& object);
	ClapTrap& operator=(const ClapTrap& object);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
