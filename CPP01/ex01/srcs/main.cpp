#include "../inc/Zombie.hpp"

int main(void) {
	int N = 5;

	Zombie* horde = zombieHorde(N, "Paul");
	if (!horde)
		return 1;
	for (int i = 0; i < N; ++i) {
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
