
#include "Animal.hpp"


Animal::Animal() : type("") {
	std::cout << "Animal ctor" << std::endl;
};

Animal::Animal(const Animal &other) : type(other.type) {};

Animal& Animal::operator=(const Animal &other) {

	if (this != &other) {
		type = other.type;
	}
	return *this;
};

Animal::~Animal() {
	std::cout << "Animal dtor" << std::endl;
};

void Animal::setType(const std::string name) {
	this->type = name;
};

const std::string& Animal::getType() const {
	return this->type;
};
