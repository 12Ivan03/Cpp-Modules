
#include "Brain.hpp"

Brain::Brain() {

	std::cout << "Brain ctor" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
};

Brain::Brain(const Brain &other) {

	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
};

Brain& Brain::operator=(const Brain &other) {

	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
};
		
Brain::~Brain() {
	std::cout << "Brain dtor" << std::endl;
};

void Brain::setIdeas(int index, const std::string &idea) {
	ideas[index] = idea;
};

std::string& Brain::getIdea(int index) {
	return ideas[index];
};
