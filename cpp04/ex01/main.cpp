
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "~~~~~ Create base Animal j & i with derived respectively Cat & Dog + delete currect process ~~~~~" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl << "~~~~~ Create ZOO ~~~~~" << std::endl;
	
	const int N = 10;
	Animal* zoo[N];
	for (int k = 0; k < N; ++k) {
		std::cout << '\t' << k + 1 << " -> ";
		if (k < 5) zoo[k] = new Dog();
		else zoo[k] = new Cat();
	}

	std::cout << std::endl << "~~~~~ Get ZOO types: ~~~~~" << std::endl;

	for (int k = 0; k < N; ++k) {
		std::cout << '\t' << k + 1 << ": " << zoo[k]->getType() << ": ";
		zoo[k]->makeSound();
	}

	std::cout << std::endl << "~~~~~ Dtor of the ZOO ~~~~~" << std::endl;
	
	for (int k = 0; k < N; ++k) {
		std::cout << '\t' << k + 1<< std::endl;
		delete zoo[k];
	}; 

	std::cout << std::endl << std::endl << "~~~~~ Cat Ideas turn ~~~~~" << std::endl << std::endl;

	std::cout << "Cat c brain[0] set to: climb curtain" << std::endl;
	Cat c; c.createIdea(0, "climb curtain");

	std::cout << std::endl << "Cat d created and asigned operator with Cat c" << std::endl;
	Cat d; d = c;

	std::cout << std::endl << "Cat c brain[0] changed to: scrach everyone" << std::endl;
	c.createIdea(0, "scrach everyone");
	std::cout << "c.idea[0] = " << c.pullIdea(0) << std::endl;
	std::cout << "d.idea[0] = " << d.pullIdea(0)  << std::endl;

	std::cout << std::endl << "~~~~~ Dog Ideas turn ~~~~~" << std::endl << std::endl;

	std::cout << "Dog f brain[0] set to: climb curtain" << std::endl;
	Dog f; f.createIdea(0, "climb curtain");

	std::cout << std::endl << "Dog g created and asigned operator with Dog f" << std::endl;
	Dog g; g = f;

	std::cout << std::endl << "Dog f brain[0] changed to: scrach everyone" << std::endl;
	f.createIdea(0, "scrach everyone");
	std::cout << "f.idea[0] = " << f.pullIdea(0) << std::endl;
	std::cout << "g.idea[0] = " << g.pullIdea(0) << std::endl;
	std::cout << std::endl <<  "~~~~~ Called automatic delete on the heap ~~~~~\n" << std::endl;

	return 0;
}