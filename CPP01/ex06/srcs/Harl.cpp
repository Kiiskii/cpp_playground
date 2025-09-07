#include "../inc/Harl.hpp"

void Harl::debug(void) {
	std::cout << "[DEBUG] I love having extra bacon for my burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level) {
	void (Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs[i])();
			return ;
		}
	}
}
