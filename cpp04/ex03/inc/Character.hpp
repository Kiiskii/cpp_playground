#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INV_SLOTS 4

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* inv[INV_SLOTS];
public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
