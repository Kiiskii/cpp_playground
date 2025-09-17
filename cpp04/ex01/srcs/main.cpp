#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "-------------- BASIC TESTS --------------" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << "dog type: " << dog->getType() << std::endl;
        std::cout << "cat type: " << cat->getType() << std::endl;

        dog->makeSound();
        cat->makeSound();

        delete dog;
        delete cat;
    }

    std::cout << "\n-------------- DOG BRAIN TESTS --------------" << std::endl;
    {
		std::cout << "\n-- Default Brain ideas --" << std::endl;
		Dog dog_default;
		std::cout << "dog_default idea[0]: " << dog_default.getIdea(0) << std::endl;
		std::cout << "dog_default idea[1]: " << dog_default.getIdea(1) << std::endl;
		std::cout << "dog_default idea[2]: " << dog_default.getIdea(2) << std::endl;
		std::cout << "dog_default idea[3]: " << dog_default.getIdea(3) << std::endl; // will cycle back to "I want to eat"
		std::cout << "---------------------------------------" << std::endl;
		Dog dog1;
		dog1.setIdea(0, "Chasing the mailman");
		dog1.setIdea(1, "Eating dinner");
		std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;

		std::cout << "\n-- Copy constructor test --" << std::endl;
		Dog dog2(dog1);
		std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;
		dog2.setIdea(0, "Guarding the house");
		std::cout << "dog1 idea[0] after dog2 change: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog2 idea[0] after change: " << dog2.getIdea(0) << std::endl;

		std::cout << "\n-- Assignment operator test --" << std::endl;
		Dog dog3;
		dog3 = dog1;
		std::cout << "dog3 idea[1]: " << dog3.getIdea(1) << std::endl;
		dog3.setIdea(1, "Sleeping all day");
		std::cout << "dog1 idea[1] after dog3 change: " << dog1.getIdea(1) << std::endl;
		std::cout << "dog3 idea[1] after change: " << dog3.getIdea(1) << std::endl;
	}

	std::cout << "\n-------------- CAT BRAIN TESTS --------------" << std::endl;
	{
		std::cout << "\n-- Default Brain ideas --" << std::endl;
		Cat cat_default;
		std::cout << "cat_default idea[0]: " << cat_default.getIdea(0) << std::endl;
		std::cout << "cat_default idea[1]: " << cat_default.getIdea(1) << std::endl;
		std::cout << "cat_default idea[2]: " << cat_default.getIdea(2) << std::endl;
		std::cout << "cat_default idea[3]: " << cat_default.getIdea(3) << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		Cat cat1;
		cat1.setIdea(0, "Climbing the curtains");
		cat1.setIdea(1, "Napping in the sun");
		std::cout << "cat1 idea[0]: " << cat1.getIdea(0) << std::endl;
		std::cout << "cat1 idea[1]: " << cat1.getIdea(1) << std::endl;

		std::cout << "\n-- Copy constructor test --" << std::endl;
		Cat cat2(cat1);
		std::cout << "cat2 idea[0]: " << cat2.getIdea(0) << std::endl;
		cat2.setIdea(0, "Scratching the sofa");
		std::cout << "cat1 idea[0] after cat2 change: " << cat1.getIdea(0) << std::endl;
		std::cout << "cat2 idea[0] after change: " << cat2.getIdea(0) << std::endl;

		std::cout << "\n-- Assignment operator test --" << std::endl;
		Cat cat3;
		cat3 = cat1;
		std::cout << "cat3 idea[1]: " << cat3.getIdea(1) << std::endl;
		cat3.setIdea(1, "Chasing shadows");
		std::cout << "cat1 idea[1] after cat3 change: " << cat1.getIdea(1) << std::endl;
		std::cout << "cat3 idea[1] after change: " << cat3.getIdea(1) << std::endl;
	}


	std::cout << "\n-------------- ARRAY TEST --------------" << std::endl;
	{
		const int N = 4;
		Animal* animals[N];

		for (int i = 0; i < N; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < N; i++) {
			animals[i]->makeSound();
		}

		for (int i = 0; i < N; i++) {
			delete animals[i];
		}
	}

	return 0;
}
