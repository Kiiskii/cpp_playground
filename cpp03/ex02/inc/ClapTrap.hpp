#pragma once

#include <iostream>
#include <string>

class ClapTrap {
protected:
	std::string _name;
	int _health;
	int _energy;
	int _atkDmg;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& object);
	ClapTrap& operator=(const ClapTrap& object);
	virtual ~ClapTrap();

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
