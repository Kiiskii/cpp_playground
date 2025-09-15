#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n-------------- SCAVTRAP TEST -------------" << std::endl;

	std::cout << "\n-------------- TEST CONSTRUCTORS -------------\n" << std::endl;
	ScavTrap scav_zero;
	ScavTrap scav_one("scav_One");
	ScavTrap scav_two(scav_one);
	ScavTrap scav_three;
	scav_three = scav_one;
	ScavTrap scav_sm("scav_Someone");

	std::cout << "\n----------- TEST ATTACK AND ENERGY -----------\n" << std::endl;
	for (int i = 0; i < 16; i++) {
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


	std::cout << "\n-------------- FRAGTRAP TEST -------------" << std::endl;

	std::cout << "-------------- TEST CONSTRUCTORS -------------\n" << std::endl;
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
