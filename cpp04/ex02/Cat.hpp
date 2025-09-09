
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		virtual void		makeSound() const;
		
		int					setBrain(int index, const std::string &idea);
		const std::string	&getBrainIdea(int index) const;
};

#endif