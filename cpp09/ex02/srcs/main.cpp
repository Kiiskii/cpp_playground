#include "../inc/PmergeMe.hpp"
#include <chrono>
#include <exception>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::duration<double, std::micro> Micro;

int main(int ac, char** av) {
	PmergeMe pm;
	try {
		pm.parseInput(ac, av);
		std::cout << "Before: ";
		pm.printVector();

		auto startVec = Clock::now();
		pm.sortVector();
		auto endVec = Clock::now();
		double elapsedVec = Micro(endVec - startVec).count();

		std::cout << "After: ";
		pm.printVector();
		std::cout << "Time to process range of " << ac - 1
			<< " elements with std::vector: " << elapsedVec
			<< " us" << std::endl;

		auto startDeq = Clock::now();
		pm.sortDeque();
		auto endDeq = Clock::now();
		double elapsedDeq = Micro(endDeq - startDeq).count();

		std::cout << "Time to process range of " << ac - 1
			<< " elements with std::deque:  " << elapsedDeq
			<< " us" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << C_R << e.what() << C_RST << std::endl;
		return 1;
	}
	return 0;
}
