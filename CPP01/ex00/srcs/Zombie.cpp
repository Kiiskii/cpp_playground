#include "../inc/Zombie.hpp"

Zombie::Zombie (std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << ": was destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
