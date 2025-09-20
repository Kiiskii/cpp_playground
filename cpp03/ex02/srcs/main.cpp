#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	std::cout << "\n-------------- FRAGTRAP TEST -------------\n" << std::endl;

	FragTrap frag_zero;
	FragTrap frag_one("frag_One");
	FragTrap frag_two(frag_one);
	FragTrap frag_three;
	frag_three = frag_one;
	FragTrap frag_sm("frag_Someone");

	std::cout << "\n----------- TEST ATTACK AND ENERGY -----------\n" << std::endl;
	for (int i = 0; i < 16; i++) {
		std::cout << i + 1 << ": ";
		frag_one.attack("Someone");
	}

	std::cout << "\n---------------- TEST DAMAGE -----------------\n" << std::endl;
	frag_sm.takeDamage(0);
	frag_sm.takeDamage(20);
	frag_sm.takeDamage(30);
	frag_sm.takeDamage(70);
	frag_sm.takeDamage(70);

	std::cout << "\n---------------- TEST REPAIR -----------------\n" << std::endl;
	frag_one.beRepaired(10);
	frag_sm.beRepaired(10);
	frag_zero.beRepaired(10);

	std::cout << "\n--------------- TEST HIGH FIVE ----------------\n" << std::endl;
	frag_one.highFivesGuys();
	frag_sm.highFivesGuys();
	frag_zero.highFivesGuys();
	std::cout << "\n-------------- DESTRUCTORS CALL ---------------\n" << std::endl;
}
