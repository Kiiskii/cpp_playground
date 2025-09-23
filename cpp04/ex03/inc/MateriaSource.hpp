#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAT_INV_SLOTS 4

class MateriaSource : public IMateriaSource {
private:
	AMateria* inv[MAT_INV_SLOTS];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(const std::string& type);
};
