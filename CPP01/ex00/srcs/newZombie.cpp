#include "../inc/Zombie.hpp"

Zombie* newZombie(std::string name) {
	try {
		Zombie* z = new Zombie(name);
		return z;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation error: " << e.what() << std::endl;
		return nullptr;
	}
}
