
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	setType("Wrong Cat");
	std::cout << "Wrong Cat ctor" << std::endl;
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Wrong Cat copy" << std::endl;
};
		
WrongCat& WrongCat::operator=(const WrongCat &other) {

	std::cout << "Wrong Cat copy operator" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
};
		
WrongCat::~WrongCat() {
	std::cout << "Wrong Cat dtor" << std::endl;
};

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
};

