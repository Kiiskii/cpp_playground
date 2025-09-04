#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main(void) {
	std::cout << "Tests:" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		HumanB tim("Tim");
		tim.attack();
	}
	std::cout << "------------------------------------" << std::endl;
	std::cout << "End of tests" << std::endl;

	return 0;
}
