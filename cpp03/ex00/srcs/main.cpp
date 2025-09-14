#include "ClapTrap.hpp"

int main(void) {
	std::cout << "\n-------------- TEST CONSTRUCTORS -------------\n" << std::endl;
	ClapTrap clap_zero;
	ClapTrap clap_one("One");
	ClapTrap clap_two(clap_one);
	ClapTrap clap_three;
	clap_three = clap_one;
	ClapTrap clap_sm("Someone");

	std::cout << "\n----------- TEST ATTACK AND ENERGY -----------\n" << std::endl;
	for (int i = 0; i < 16; i++) {
	std::cout << i + 1 << ": ";
	clap_one.attack("Someone");
	}

	std::cout << "\n---------------- TEST DAMAGE -----------------\n" << std::endl;
	clap_sm.takeDamage(0);
	clap_sm.takeDamage(2);
	clap_sm.takeDamage(3);
	clap_sm.takeDamage(10);
	clap_sm.takeDamage(10);

	std::cout << "\n---------------- TEST REPAIR -----------------\n" << std::endl;
	clap_one.beRepaired(10);
	clap_sm.beRepaired(10);
	clap_zero.beRepaired(10);

	std::cout << "\n-------------- DESTRUCTORS CALL ---------------\n" << std::endl;
}
