
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
	this->type = "Dog";
	std::cout << "Dog-ctor" << std::endl;
};

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {};

Dog& Dog::operator=(const Dog &other) {

	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
};

Dog::~Dog() {
	delete brain;
	std::cout << "D-dtor" << std::endl;
};

void Dog::makeSound() const {
	std::cout << "Bark bark" << std::endl;
};


int	Dog::createIdea(int index, const std::string &idea) {
	if (index < 0 || index > 99) {
		std::cout << "ERROR: incurrect index" << std::endl;
		return -1;
	}
	brain->setIdea(index, idea);
	return 0;
};
	
std::string& Dog::pullIdea(int index) const {
	return brain->getIdea(index);
};

