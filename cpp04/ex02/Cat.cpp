
#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
	std::cout << "Cat ctor" << std::endl;
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
	std::cout << "Cat dtor" << std::endl;
	delete brain;
};

void	Cat::makeSound() const {
	std::cout << "Meeoooooow" << std::endl;
};
		
int	Cat::setBrain(int index, const std::string &idea) {
	if (index < 0 || index  > 100) {
		std::cout << "ERROR: invalid index" << std::endl;
		return -1;
	}
	brain->setIdeas(index, idea);
	return 0;
};
		
const std::string& Cat::getBrainIdea(int index) const {
	return brain->getIdea(index);
};
