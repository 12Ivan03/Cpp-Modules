
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string type;
		void setType(const std::string name);
	
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const = 0;
		const std::string &getType() const;

};

#endif