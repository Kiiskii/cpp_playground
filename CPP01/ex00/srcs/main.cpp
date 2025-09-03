#include "../inc/Zombie.hpp"

int main(void) {
	std::cout << "Tests:" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	Zombie pekka("pekka");
	pekka.announce();

	randomChump("ville");

	Zombie* blob = newZombie("blob");
	if (!blob)
		return 1;
	blob->announce();
	delete blob;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "End tests." << std::endl;
	return 0;
}
