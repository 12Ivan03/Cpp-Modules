
#include "Serializer.hpp"

int	main(void) {

	Data phoneBook;
	phoneBook.name = "Ivan";
	phoneBook.age = 18;
	phoneBook.phoneNumber = 124761364;
	uintptr_t ser;
	Data *back;

	Data *p = &phoneBook;
	std::cout << "Data *p = &phoneBook --> address = " << p << std::endl;

	ser = Serializer::serialize(p);
	std::cout << "ser = Serializer::serialize(p);\nser = " << ser << std::endl;
	back = Serializer::deserialize(ser);
	std::cout << "back = Serializer::deserialize(ser);\nback = " << back << std::endl;


	return 0;
}