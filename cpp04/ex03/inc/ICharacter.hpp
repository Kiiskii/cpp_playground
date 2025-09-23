#pragma once

#include <iostream>
class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {};

	virtual const std::string& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int i) = 0;
	virtual void use(int i, ICharacter& target) = 0;
};
