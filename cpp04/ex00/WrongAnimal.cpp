
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal") {
	std::cout << "WrongAnimal ctor" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WrongAnimal copy" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	
	std::cout << "WrongAnimal copy operator" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "Animal dtor" << std::endl;
};

void WrongAnimal::makeSound() const {
	std::cout << "Animal noices" << std::endl;
};

void	WrongAnimal::setType(const std::string &name) {
	this->type = name;
};

const std::string& WrongAnimal::getType() const {
	return this->type;
};
		