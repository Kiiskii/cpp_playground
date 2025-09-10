#pragma once

#include <iostream>
#include <string>

class Zombie {
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	Zombie(std::string name);

	void announce();
	void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);
