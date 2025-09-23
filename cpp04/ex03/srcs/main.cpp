#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void test1() {
	std::cout << std::endl << "Test 1: AMateria basic test" << std::endl << std::endl;

	const AMateria *ice = new Ice();
	const AMateria *cure = new Cure();
	Ice ice2;
	Ice copy(ice2);
	Ice ice3;

	ice3 = copy;

	std::cout << std::endl;
	std::cout << "Type of Ice object just created: " << ice->getType() << std::endl;
	std::cout << "Type of Cure object just created: " << cure->getType() << std::endl;

	delete ice;
	delete cure;
}

void test2() {
	std::cout << std::endl << "Test 2: ice basic test" << std::endl << std::endl;

	AMateria *ice = new Ice();
	AMateria *ice2 = new Ice();

	*ice2 = *ice;
	std::cout << std::endl;
	std::cout << "Type of ice2 object just created: " << ice2->getType() << std::endl;

	delete ice;
	delete ice2;
}

void test3() {
	std::cout << std::endl << "Test 3: cure basic test" << std::endl << std::endl;

	AMateria *cure = new Cure();
	AMateria *cure2 = new Cure();

	*cure2 = *cure;

	Cure cure3;
	Cure copy(cure3);
	Cure cure4;

	cure4 = copy;

	std::cout << std::endl;
	std::cout << "Type of cure2 object just created: " << cure2->getType() << std::endl;

	delete cure;
	delete cure2;
}

void test4() {
	std::cout << std::endl << "Test 4: Character tests" << std::endl << std::endl;

	Character bob;
	std::cout << "Char created: " << bob.getName() << std::endl;

	Character* bob2 = new Character("bob2");
	std::cout << "Char created: " << bob2->getName() << std::endl;

	Character bob3("bob3");
	std::cout << "Char created: " << bob3.getName() << std::endl;

	bob = bob3;
	std::cout << "Bob got new name: " << bob.getName() << std::endl;

	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	bob.equip(ice);
	bob2->equip(cure);

	Character bob4(bob);

	bob.use(0, *bob2);
	bob2->use(0, bob);

	bob.use(1, *bob2); //empty slot test
	bob2->use(1, bob); //empty slot test

	bob.unequip(0);
	delete ice;
	bob.unequip(1); //empty slot test


	AMateria *ice1 = new Ice();
	AMateria *cure1 = new Cure();
	AMateria *ice2 = new Ice();
	AMateria *cure2 = new Cure();
	AMateria *cure3 = new Cure();

	bob.equip(ice1);
	bob.equip(cure1);
	bob.equip(ice2);
	bob.equip(cure2);
	bob.equip(cure3);

	bob2->unequip(0);
	delete cure;
	bob2->unequip(1); //empty slot test
	delete bob2;
	delete cure3;
}

void test5() {
	std::cout << std::endl << "Test 5: MateriaSource tests" << std::endl << std::endl;

	IMateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	MateriaSource src2;
	src2.learnMateria(new Cure());

	MateriaSource src3(*static_cast<const MateriaSource*>(src1));

	src2 = src3;

	ICharacter* bob = new Character("bob");
	ICharacter* bob2 = new Character("bob2");

	AMateria* new_materia0;
	new_materia0 = src3.createMateria("cure");
	bob->equip(new_materia0);
	AMateria* new_materia1 = src3.createMateria("ice");
	bob2->equip(new_materia1);
	AMateria* new_materia2 = src3.createMateria("non_existent");
	bob2->equip(new_materia2);

	bob->use(0, *bob2);
	bob2->use(0, *bob);

	AMateria* OnGround[100];
	for (int i = 0; i < 100; i++)
		OnGround[i] = nullptr;
	OnGround[0] = new_materia0;
	bob->unequip(0);
	bob->unequip(1); //empty slot test

	for (int i = 0; i < 100; i++)
		delete OnGround[i];
	delete bob;
	delete bob2;
	delete src1;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return (0);
}
