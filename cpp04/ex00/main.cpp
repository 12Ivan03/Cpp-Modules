
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "~~~~~ Type of Animals ~~~~~" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << std::endl << "~~~~~ Type sounds Animals make ~~~~~" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << std::endl << "~~~~~ Cleaning up in order ~~~~~" << std::endl;
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	
	std::cout << std::endl << "~~~~~ Single Animal test ~~~~~" << std::endl;
	const Animal* k = new Dog();

	std::cout << k->getType() << std::endl;
	k->makeSound();

	delete k;

	std::cout << std::endl << std::endl << "~~~~~ Wrong ~~~~~" << std::endl;;

	const WrongAnimal* w = new WrongCat();

	std::cout << "Type of Animal: " << w->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Wrong Cat makeSound -> ";
	w->makeSound();

	delete k;

	return 0;
}