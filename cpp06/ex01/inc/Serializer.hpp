#pragma once

#include "Data.hpp"
#include <cstdint>

#define C_G		"\033[0;32m\001"
#define C_R		"\033[0;31m\001"
#define C_RST	"\033[0m\002"

class Serializer {
private:
	Serializer() = delete;
	Serializer(const Serializer& other) = delete;
	Serializer& operator=(const Serializer& other) = delete;
	~Serializer() = delete;
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
