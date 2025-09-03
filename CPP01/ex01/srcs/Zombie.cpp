#include "../inc/Zombie.hpp"

Zombie::Zombie() {
	_name = "Unnamed";
}

Zombie::Zombie (std::string name) {
	_name = name;
}

void Zombie::announce(void) {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string& name) {
	_name = name;
	std::cout << "Zombie was named: " << _name << std::endl;
}
