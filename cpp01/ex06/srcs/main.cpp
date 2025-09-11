#include "../inc/Harl.hpp"

int getLevelIndex(const std::string& level) {
	if (level == "DEBUG")
		return 0;
	if (level == "INFO")
		return 1;
	if (level == "WARNING")
		return 2;
	if (level == "ERROR")
		return 3;
	return -1;
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}

	Harl harl;
	std::string level = av[1];
	int levelIndex = getLevelIndex(level);

	switch (levelIndex) {
		case 0:
			harl.complain("DEBUG");
			[[fallthrough]];
		case 1:
			harl.complain("INFO");
			[[fallthrough]];
		case 2:
			harl.complain("WARNING");
			[[fallthrough]];
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
