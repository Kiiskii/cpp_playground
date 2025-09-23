#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	{
		std::cout << "-------------- TEST CONSTRUCTORS -------------\n" << std::endl;
		Animal animal;
		Dog dog;
		Cat cat;
		Animal animal_cat = cat;
		Animal animal_dog(dog);

		std::cout << "\n--------------- TEST makeSound() --------------\n" << std::endl;
		std::cout << "animal: ";
		animal.makeSound();
		std::cout << "\nanimal_cat: ";
		animal_cat.makeSound();
		std::cout << "animal_dog: ";
		animal_dog.makeSound();
		std::cout << "dog: ";
		dog.makeSound();
		std::cout << "cat: ";
		cat.makeSound();

		std::cout << "\n----------------- DESTRUCTORS ----------------\n" << std::endl;
	}

	{
		std::cout << "\n--------------- TEST FROM SUBJECT --------------\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << ": ";
		j->makeSound();
		std::cout << i->getType() << ": ";
		i->makeSound();  // will output the cat sound!
		std::cout << meta->getType() << ": ";
		meta->makeSound();
		std::cout << "\n----------------- DESTRUCTORS ----------------\n" << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\n--------------- TEST WRONG VERSION -------------\n"
				  << std::endl;
		WrongAnimal wrong_animal;
		WrongCat wrong_cat;
		WrongAnimal& wrong_animal_cat = wrong_cat;

		std::cout << "\n--------------- TEST makeSound() --------------\n"
				  << std::endl;
		std::cout << "wrong_animal: ";
		wrong_animal.makeSound();
		std::cout << "wrong_animal_cat: ";
		wrong_animal_cat.makeSound();
		std::cout << "wrong_cat: ";
		wrong_cat.makeSound();

		std::cout << "\n----------------- DESTRUCTORS ----------------\n"
				  << std::endl;
	}
}
