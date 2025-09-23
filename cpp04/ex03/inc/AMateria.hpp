#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;
public:
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
