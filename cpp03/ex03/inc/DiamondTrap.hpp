#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& object);
	DiamondTrap& operator=(const DiamondTrap& object);
	~DiamondTrap() override;

	using ScavTrap::attack; // explicitly calls ScavTraps attack() to avoid ambiguity.
	void whoAmI();
};
