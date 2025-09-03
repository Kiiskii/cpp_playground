#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	try {
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; ++i)
			horde[i].setName(name);
		return horde;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation error: " << e.what() << std::endl;
		return nullptr;
	}
}
