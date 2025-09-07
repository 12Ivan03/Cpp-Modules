
#include "Dog.hpp"


Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "Dog ctor" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy ctor" << std::endl;
};

Dog& Dog::operator=(const Dog &other) {

	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Dog operator" << std::endl;
	return *this;
};

Dog::~Dog() {
	std::cout << "Dog dtor" << std::endl;
};

void Dog::makeSound() const {
	std::cout << "Dog says: bark bark" << std::endl;
};
