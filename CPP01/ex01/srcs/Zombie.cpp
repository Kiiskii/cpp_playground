#include "../inc/Zombie.hpp"

Zombie::Zombie() {
	_name = "Unnamed";
}

Zombie::Zombie (std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << ": was destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	_name = name;
	std::cout << "Zombie was named: " << _name << std::endl;
}
