
#include "Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "Cat ctor" << std::endl;
};

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy ctor" << std::endl;
};

Cat& Cat::operator=(const Cat &other) {

	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat copy ctor" << std::endl;
	return *this;
};

Cat::~Cat() {
	std::cout << "Cat dtor" << std::endl;
};

void Cat::makeSound() const {
	std::cout << "Cat says: purr purr" << std::endl;
};
