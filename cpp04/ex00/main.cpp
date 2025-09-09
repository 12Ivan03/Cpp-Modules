
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	
	const Animal* k = new Dog();

	std::cout << k->getType() << std::endl;
	k->makeSound();

	delete k;

	return 0;
}