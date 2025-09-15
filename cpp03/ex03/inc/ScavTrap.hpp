#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	static const int defaultEnergy = 50;
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& object);
	ScavTrap& operator=(const ScavTrap& object);
	~ScavTrap() override;

	void attack(const std::string& target) override;
	void guardGate();
};
