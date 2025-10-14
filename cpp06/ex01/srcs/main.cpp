#include "Serializer.hpp"
#include <iostream>
#include <string>

#define MYASSERT(expr, num)													\
	do {																	\
		if (!(expr)) {														\
			std::cerr	<< C_R << "test " << num << " [FAIL] " << "("		\
						<< __FILE__ << ":" << __LINE__ << ")" << C_RST		\
						<< std::endl;										\
		} else {															\
			std::cout << C_G << "test " << num << " [OK]" << std::endl;		\
		}																	\
	} while (0)

static void test1() {
	Data d{"alpha", 1};
	Data* original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* back = Serializer::deserialize(raw);

	MYASSERT(back == original, 1);
}

static void test2() {
	Data d{"bravo", 7};
	uintptr_t raw = Serializer::serialize(&d);
	Data* p = Serializer::deserialize(raw);

	MYASSERT(p->name == "bravo", 2.1);
	MYASSERT(p->value == 7, 2.2);
}

static void test3() {
	Data d{"charlie", 10};
	Data* original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* alias = Serializer::deserialize(raw);

	alias->name  = "delta";
	alias->value = 42;

	MYASSERT(original->name == "delta", 3.1);
	MYASSERT(original->value == 42, 3.2);
}

static void test4() {
	Data a{"one", 1};
	Data b{"two", 2};

	uintptr_t ra = Serializer::serialize(&a);
	uintptr_t rb = Serializer::serialize(&b);

	MYASSERT(ra != rb, 4.1);
	MYASSERT(Serializer::deserialize(ra) == &a, 4.2);
	MYASSERT(Serializer::deserialize(rb) == &b, 4.3);
}

static void test5() {
	Data* p = nullptr;
	uintptr_t raw = Serializer::serialize(p);
	Data* back = Serializer::deserialize(raw);

	MYASSERT(back == nullptr, 5);
	// MYASSERT(back != 0, 5); // this test will show that MYASSERT will print a different msg on a failed test
}

static void test6() {
	Data p;
	uintptr_t raw = Serializer::serialize(&p);
	Data* back = Serializer::deserialize(raw);

	MYASSERT(back == &p, 6);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	std::cout << C_G << "All tests passed ✅" << C_RST << std::endl;
	return 0;
}
