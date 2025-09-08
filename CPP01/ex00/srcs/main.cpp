#include "../inc/Zombie.hpp"

int main(void) {
	std::cout << "Tests:" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	Zombie pekka("pekka");
	pekka.announce();

	Zombie* blob = newZombie("blob");
	if (!blob)
		return 1;
	blob->announce();

	randomChump("ville");
	delete blob;

	return 0;
}
