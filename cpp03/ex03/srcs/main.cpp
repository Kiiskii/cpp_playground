#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "\n-------------- TEST DIAMONDTRAP -------------\n" << std::endl;
	DiamondTrap diamond_zero;
	DiamondTrap diamond_one("diamond_One");
	DiamondTrap diamond_two(diamond_one);
	DiamondTrap diamond_three;
	diamond_three = diamond_one;
	DiamondTrap diamond_sm("diamond_Someone");

	std::cout << "\n----------- TEST ATTACK AND ENERGY -----------\n" << std::endl;
	for (int i = 0; i < 60; i++) {
		std::cout << i + 1 << ": ";
		diamond_one.attack("Someone");
	}

	std::cout << "\n---------------- TEST DAMAGE -----------------\n" << std::endl;
	diamond_sm.takeDamage(0);
	diamond_sm.takeDamage(20);
	diamond_sm.takeDamage(30);
	diamond_sm.takeDamage(70);
	diamond_sm.takeDamage(10);

	std::cout << "\n---------------- TEST REPAIR -----------------\n" << std::endl;
	diamond_one.beRepaired(10);
	diamond_sm.beRepaired(10);
	diamond_zero.beRepaired(10);

	std::cout << "\n---------------- TEST WHOAMI -----------------\n" << std::endl;
	diamond_one.whoAmI();
	diamond_zero.whoAmI();
	diamond_sm.whoAmI();
	std::cout << "\n-------------- DESTRUCTORS CALL ---------------\n" << std::endl;
}
