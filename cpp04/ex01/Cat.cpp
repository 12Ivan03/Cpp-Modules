
#include "Cat.hpp"


Cat::Cat() : Animal(), brain(new Brain()) {
	std::cout << "Cat-ctor" << std::endl;
	this->type = "Cat";
};

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {};

Cat& Cat::operator=(const Cat &other) {

	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
};

Cat::~Cat() {
	delete brain;
	std::cout << "C-dtor" << std::endl;
};

void Cat::makeSound() const {
	std::cout << "purr purr" << std::endl;
};
