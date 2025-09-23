#include "Character.hpp"

Character::Character() : _name("noName") {
	for (int i = 0; i < INV_SLOTS; i++)
		inv[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < INV_SLOTS; i++)
		inv[i] = nullptr;
}

Character::Character(const Character& other) : _name(other.getName()) {
	for (int i = 0; i < INV_SLOTS; i++) {
		if (other.inv[i] != nullptr)
			inv[i] = other.inv[i]->clone();
		else
			inv[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other.getName();
		for (int i = 0; i < INV_SLOTS; i++) {
			if (inv[i] != nullptr)
				delete inv[i];
			if (other.inv[i] != nullptr)
				inv[i] = other.inv[i]->clone();
			else
				inv[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < INV_SLOTS; i++) {
		if (inv[i] != nullptr) {
			delete inv[i];
			inv[i] = nullptr;
		}
	}
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == nullptr) {
		std::cout << "There is no item to equip." << std::endl;
		return ;
	}
	for (int i = 0; i < INV_SLOTS; i++) {
		if (inv[i] == nullptr) {
			std::cout << "Character " << this->getName() << " equipped " << m->getType() << "." << std::endl;
			inv[i] = m;
			return ;
		}
	}
	std::cout << "No room in inventory to equip " << m->getType() << "." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INV_SLOTS) {
		std::cout << "Invalid index for inventory slot." << std::endl;
		return ;
	}
	if (inv[idx] != nullptr)
		std::cout << "Character " << this->getName() << " unequipped " << inv[idx]->getType() << "." << std::endl;
	inv[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= INV_SLOTS) {
		std::cout << "Invalid index for inventory slot." << std::endl;
		return ;
	}
	if (inv[idx] == nullptr) {
		std::cout << "No item in this inventory slot." << std::endl;
		return ;
	}
	inv[idx]->use(target);
}
