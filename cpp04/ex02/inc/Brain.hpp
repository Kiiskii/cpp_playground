#pragma once

#include <iostream>
#include <string>

#define IDEAS_AMOUNT 100

class Brain {
private:
	std::string _ideas[IDEAS_AMOUNT];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void setIdea(int i, const std::string& str);
	const std::string& getIdea(int i) const;
};
