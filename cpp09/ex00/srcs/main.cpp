#include "../inc/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		std::string filename = argv[1];
		btc.processInput(filename);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
