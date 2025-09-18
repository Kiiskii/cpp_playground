#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "\n-------------- ABSTRACT CLASS TESTS --------------" << std::endl;
	{
		// Polymorphism check
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << "dog type: " << dog->getType() << std::endl;
		std::cout << "cat type: " << cat->getType() << std::endl;

		dog->makeSound(); // should print "WOOF WOOF"
		cat->makeSound(); // should print "MEOW MEOW"

		delete dog;
		delete cat;

		// Uncommenting the next line should give a compiler error
		// Animal a;  // Error: variable type 'Animal' is an abstract class
	}
}
