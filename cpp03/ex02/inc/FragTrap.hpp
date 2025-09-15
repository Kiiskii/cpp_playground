#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& object);
	FragTrap& operator=(const FragTrap& object);
	~FragTrap() override;

	void highFivesGuys();
};
