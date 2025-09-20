#include "ScavTrap.hpp"

int main(void) {
	std::cout << "\n-------------- SCAVTRAP TEST -------------\n" << std::endl;

	ScavTrap scav_zero;
	ScavTrap scav_one("scav_One");
	ScavTrap scav_two(scav_one);
	ScavTrap scav_three;
	scav_three = scav_one;
	ScavTrap scav_sm("scav_Someone");

	std::cout << "\n----------- TEST ATTACK AND ENERGY -----------\n" << std::endl;
	for (int i = 0; i < 52; i++) {
		std::cout << i + 1 << ": ";
		scav_one.attack("Someone");
	}

	std::cout << "\n---------------- TEST DAMAGE -----------------\n" << std::endl;
	scav_sm.takeDamage(0);
	scav_sm.takeDamage(20);
	scav_sm.takeDamage(30);
	scav_sm.takeDamage(70);
	scav_sm.takeDamage(70);

	std::cout << "\n---------------- TEST REPAIR -----------------\n" << std::endl;
	scav_one.beRepaired(10);
	scav_sm.beRepaired(10);
	scav_zero.beRepaired(10);

	std::cout << "\n--------------- TEST GUARDGATE ----------------\n" << std::endl;
	scav_zero.guardGate();
	scav_two.guardGate();

	std::cout << "\n-------------- DESTRUCTORS CALL ---------------\n" << std::endl;
}
