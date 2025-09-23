#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAT_INV_SLOTS; i++)
		inv[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < MAT_INV_SLOTS; i++) {
		if (other.inv[i] != nullptr)
			inv[i] = other.inv[i]->clone();
		else
			inv[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < MAT_INV_SLOTS; i++) {
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

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAT_INV_SLOTS; i++)
		delete inv[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MAT_INV_SLOTS; i++) {
		if (inv[i] == nullptr) {
			inv[i] = m;
			return ;
		}
	}
	std::cout << "No room in inventory for new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < MAT_INV_SLOTS; i++) {
		if (inv[i] && inv[i]->getType() == type)
			return inv[i]->clone();
	}
	return nullptr;
}
