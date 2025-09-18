#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void makeSound() const override;
	void setIdea(int i, const std::string& str);
	const std::string& getIdea(int i) const;
};
