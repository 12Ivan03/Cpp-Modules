
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << '\n' << std::endl;

	const int N = 10;
	Animal* zoo[N];
	for (int k = 0; k < N; ++k) {
		std::cout << '\t' << k << " -> ";
		if (k < 5) zoo[k] = new Dog();
		else zoo[k] = new Cat();
	}

	std::cout << std::endl;

	for (int k = 0; k < N; ++k) {
		std::cout << '\t' << k << ": " << zoo[k]->getType() << ": ";
		zoo[k]->makeSound();
	}

	std::cout << std::endl;
	
	for (int k = 0; k < N; ++k) delete zoo[k]; // delete via base ptr


	// separator("Deep copy test: Dog");
	// Dog a; a.setIdea(0, "chase cats"); a.setIdea(1, "eat kibble");
	// Dog b = a; // copy-ctor deep copy
	// a.setIdea(0, "nap in sun");
	// std::cout << "a.idea[0] = " << a.getIdea(0) << std::endl;
	// std::cout << "b.idea[0] = " << b.getIdea(0) << " (should remain 'chase cats')" << std::endl;


	// separator("Deep copy test: Cat");
	// Cat c; c.setIdea(0, "climb curtain");
	// Cat d; d = c; // assignment deep copy
	// c.setIdea(0, "stare at void");
	// std::cout << "c.idea[0] = " << c.getIdea(0) << std::endl;
	// std::cout << "d.idea[0] = " << d.getIdea(0) << " (should remain 'climb curtain')" << std::endl;


	// separator("Polymorphic delete order");
	// Animal* p1 = new Dog();
	// Animal* p2 = new Cat();
	// delete p1; // Dog dtor -> Brain dtor -> Animal dtor (visible in logs)
	// delete p2; // Cat dtor -> Brain dtor -> Animal dtor


	// std::cout << "\nAll good in ex01.\n" << std::endl;
	return 0;
}