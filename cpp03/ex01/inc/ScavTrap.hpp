#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& object);
	ScavTrap& operator=(const ScavTrap& object);
	~ScavTrap() override;

	void attack(const std::string& target) override;
	void guardGate();
};
