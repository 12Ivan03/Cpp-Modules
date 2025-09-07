
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Default Aminal constructor" << std::endl;
};

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Copy Animal constructor" << std::endl;
};

Animal& Animal::operator=(const Animal &other) {

	if (this != &other) {
		type = other.type;
	}
	std::cout << "Operator Animal constructor" << std::endl;
	return *this;
};

Animal::~Animal() {
	std::cout << "Animal dtor" << std::endl;
};

void Animal::makeSound() const {
	std::cout << "General animal noises" << std::endl;
};

void	Animal::setType(const std::string &name) {
	this->type = name;
};

std::string	Animal::getType() const {
	std::cout << "Get Animal type: ";
	return type;
};
