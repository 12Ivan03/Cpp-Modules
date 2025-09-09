
#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
	setType("Dog");
	std::cout << "Dog ctor" << std::endl;
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
	std::cout << "Dog dtor" << std::endl;
};

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
};

int	Dog::setIdeas(int index, const std::string &idea) {

	if (index < 0 || index > 99) {
		std::cout << "ERROR: invalid index" << std::endl;
		return -1;
	}
	this->brain->setIdeas(index, idea);
	return 0;
};

const std::string&	Dog::getIdea(int index) const {
	return this->brain->getIdea(index);
};
