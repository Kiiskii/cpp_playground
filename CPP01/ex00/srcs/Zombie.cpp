#include "../inc/Zombie.hpp"

Zombie::Zombie (std::string name) {
	_name = name;
}

void Zombie::announce(void) {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
