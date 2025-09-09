
#include "Cat.hpp"


Cat::Cat() : Animal(), brain(new Brain()) {
	std::cout << "Cat-ctor" << std::endl;
	setType("Cat");
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


int	Cat::createIdea(int index, const std::string &idea) {
	if (index < 0 || index > 99) {
		std::cout << "ERROR: incurrect index" << std::endl;
		return -1;
	}
	brain->setIdea(index, idea);
	return 0;
};

std::string& Cat::pullIdea(int index) const {
	return brain->getIdea(index);
};
