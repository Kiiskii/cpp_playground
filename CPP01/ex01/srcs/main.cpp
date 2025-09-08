#include "../inc/Zombie.hpp"

int main(void) {
	int N = 5;

	Zombie* horde = zombieHorde(N, "Paul");
	std::cout << "----------------------------------" << std::endl;
	if (!horde)
		return 1;
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	std::cout << "----------------------------------" << std::endl;

	delete[] horde;
	return 0;
}
