#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	static const int defaultHealth = 100;
	static const int defaultDmg = 30;
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& object);
	FragTrap& operator=(const FragTrap& object);
	~FragTrap() override;

	void highFivesGuys();
};
