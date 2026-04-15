#include "Serializer.hpp"
#include <iostream>
#include <string>

#define MYASSERT(expr, num) ([&]() -> bool {							\
	if (!(expr)) {														\
		std::cerr	<< C_R << "test " << num << " [FAIL] " << "("		\
					<< __FILE__ << ":" << __LINE__ << ")" << C_RST		\
					<< std::endl;										\
		return false;													\
	} else {															\
		std::cout << C_G << "test " << num << " [OK]" << C_RST << std::endl;		\
		return true;													\
	}																	\
} ())

static bool test1() {
	bool testPassed = true;

	Data d{"alpha", 1};
	Data* original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* back = Serializer::deserialize(raw);

	std::cout << "  original:     " << original << std::endl;
	std::cout << "  serialized:   " << raw << std::endl;
	std::cout << "  deserialized: " << back << std::endl;
	testPassed = MYASSERT(back == original, 1);
	return testPassed;
}

static bool test2() {
	bool testPassed = true;

	Data d{"bravo", 7};
	uintptr_t raw = Serializer::serialize(&d);
	Data* p = Serializer::deserialize(raw);

	std::cout << "  original:     " << &d << std::endl;
	std::cout << "  serialized:   " << raw << std::endl;
	std::cout << "  deserialized: " << p << std::endl;
	std::cout << "  name: " << p->name << ", value: " << p->value << std::endl;
	testPassed &= MYASSERT(p->name == "bravo", 2.1);
	testPassed &= MYASSERT(p->value == 7, 2.2);

	return testPassed;
}

static bool test3() {
	bool testPassed = true;

	Data d{"charlie", 10};
	Data* original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* alias = Serializer::deserialize(raw);

	alias->name  = "delta";
	alias->value = 42;

	std::cout << "  original:     " << original << std::endl;
	std::cout << "  serialized:   " << raw << std::endl;
	std::cout << "  deserialized: " << alias << std::endl;
	std::cout << "  modified via alias -> original name: " << original->name
			  << ", value: " << original->value << std::endl;
	testPassed &= MYASSERT(original->name == "delta", 3.1);
	testPassed &= MYASSERT(original->value == 42, 3.2);

	return testPassed;
}

static bool test4() {
	bool testPassed = true;

	Data a{"one", 1};
	Data b{"two", 2};

	uintptr_t ra = Serializer::serialize(&a);
	uintptr_t rb = Serializer::serialize(&b);

	std::cout << "  a original:     " << &a << std::endl;
	std::cout << "  a serialized:   " << ra << std::endl;
	std::cout << "  a deserialized: " << Serializer::deserialize(ra) << std::endl;
	std::cout << "  b original:     " << &b << std::endl;
	std::cout << "  b serialized:   " << rb << std::endl;
	std::cout << "  b deserialized: " << Serializer::deserialize(rb) << std::endl;
	testPassed &= MYASSERT(ra != rb, 4.1);
	testPassed &= MYASSERT(Serializer::deserialize(ra) == &a, 4.2);
	testPassed &= MYASSERT(Serializer::deserialize(rb) == &b, 4.3);

	return testPassed;
}

static bool test5() {
	bool testPassed = true;

	Data* p = nullptr;
	uintptr_t raw = Serializer::serialize(p);
	Data* back = Serializer::deserialize(raw);

	std::cout << "  original:     " << p << std::endl;
	std::cout << "  serialized:   " << raw << std::endl;
	std::cout << "  deserialized: " << back << std::endl;
	testPassed = MYASSERT(back == nullptr, 5);

	return testPassed;
}

static bool test6() {
	bool testPassed = true;

	Data p;
	uintptr_t raw = Serializer::serialize(&p);
	Data* back = Serializer::deserialize(raw);

	std::cout << "  original:     " << &p << std::endl;
	std::cout << "  serialized:   " << raw << std::endl;
	std::cout << "  deserialized: " << back << std::endl;
	testPassed = MYASSERT(back == &p, 6);

	return testPassed;
}

int main() {
	bool allTestsPassed = true;

	allTestsPassed &= test1();
	allTestsPassed &= test2();
	allTestsPassed &= test3();
	allTestsPassed &= test4();
	allTestsPassed &= test5();
	allTestsPassed &= test6();

	if (allTestsPassed)
		std::cout << C_G << "All tests passed ✅" << C_RST << std::endl;
	else
		std::cout << C_R << "Not all tests passed ❌" << C_RST << std::endl;
	return 0;
}
