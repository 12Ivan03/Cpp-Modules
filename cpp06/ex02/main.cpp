
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"


int main(void) {

	std::srand(time(0));
	{
		// creationg and checking of the A B and C 
		Base *base[10];

		for (int i = 0; i < 10; i++) {
			
			base[i] = generate();
			identify(base[i]);

			// std::cout << "Create base [" << i << "] -> with address: " << base[i] << std::endl;
		}

		for (int i = 0; i < 10; i++) {
			
			std::cout << "Delete base [" << i << "] -> with address: " << base[i] << std::endl;
			delete base[i];
		}
	}

	{
		Base* res = generate();
		Base& p = *res;
		identify(p);
		delete res;
	}


	return (0);
}