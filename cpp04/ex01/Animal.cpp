
#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal-ctor" << std::endl;
};

Animal::Animal(const Animal &other) : type(other.type) {
	// std::cout << "A-copy" << std::endl;

};

Animal& Animal::operator=(const Animal &other) {
	// std::cout << "A-assign-operator" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

Animal::~Animal() {
	std::cout << "A-dtor" << std::endl;
};

void Animal::makeSound() const {
	std::cout << "Animal noices" << std::endl;
};

std::string	Animal::getType() const {
	std::cout << "getType Animal-type : " << this->type << std::endl;
	return this->type;
};

void Animal::setType(const std::string name) {
	this->type = name;
};