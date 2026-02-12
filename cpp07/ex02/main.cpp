
#include "Array.hpp"

int	main(void) {

	std::cout << "__________________________________________" << std::endl;
	std::cout << "New -> check " << std::endl;
	Array<int> check(12);

	for (unsigned int i = 0; i < 12; i++) {
		check[i] = i + 100;
	}

	for (unsigned int i = 0; i < 12; i++) {
		std::cout << check[i] << std::endl;
	}

	std::cout << "__________________________________________" << std::endl;
	std::cout << "New -> create checkJuniour(check) " << std::endl;
	Array<int> checkJuniour(check);
	
	std::cout << "1.checkJuniour - > " << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << checkJuniour[i] << std::endl;
	}

	std::cout << "1.1.checkJuniour modified + 200:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		checkJuniour[i] += 200;
	}

	std::cout << "1.2.checkJuniour - > show modification:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << checkJuniour[i] << std::endl;
	}

	std::cout << "1.3.check - > show check is not efected:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << check[i] << std::endl;
	}

	std::cout << "__________________________________________" << std::endl;
	std::cout << "New -> create checkJuniourJuniour = check " << std::endl;
	Array<int> checkJuniourJuniour(check);
	
	std::cout << "2.checkJuniourJuniour - > " << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << checkJuniourJuniour[i] << std::endl;
	}

	std::cout << "2.1.checkJuniourJuniour modified + 500:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		checkJuniourJuniour[i] += 500;
	}

	std::cout << "2.2.checkJuniourJuniour - > show modification:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << checkJuniourJuniour[i] << std::endl;
	}

	std::cout << "2.3.check - > show check is not efected:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << check[i] << std::endl;
	}

	std::cout << "__________________________________________" << std::endl;
	std::cout << "New -> create word Array -> Alisa " << std::endl;
	Array<char> alisa(12);
	for (unsigned int i = 0; i < 12; i++) {
		alisa[i] = (char)(97 + i);
	}

	Array<char> alisaJuniour(alisa);
	
	std::cout << "3.alisaJuniour - > alisaJuniour(alisa) " << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << alisaJuniour[i] << std::endl;
	}

	std::cout << "3.1.alisaJuniour modified = 65 + 1:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		alisaJuniour[i] = (char)65 + i;
	}

	std::cout << "3.2.alisaJuniour - > show modification:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << alisaJuniour[i] << std::endl;
	}

	std::cout << "3.3.alisa - > show alisa is not efected:" << std::endl;
	for (unsigned int i = 0; i < 12; i++) {
		std::cout << alisa[i] << std::endl;
	}

	{

		std::cout << "__________________________________________" << std::endl;
		std::cout << "New -> create word Array -> Bob " << std::endl;
		Array<std::string> bob(6);
		for (unsigned int i = 0; i < 6; i++) {
			bob[i] = "Hello0";
			bob[i][5] = (char)48 + i;
		}
		// bob[0] = "Hello0";
		// bob[1] = "Hello1";
		// bob[2] = "Hello2";
		// bob[3] = "Hello3";
		// bob[4] = "Hello4";
		// bob[5] = "Hello5";

		for (unsigned int i = 0; i < 6; i++) {
			std::cout << bob[i] << std::endl;
		}

		Array<std::string> bobJuniour(bob);
		
		std::cout << "3.bobJuniour - > bobJuniour(bob) " << std::endl;
		for (unsigned int i = 0; i < 6; i++) {
			std::cout << bobJuniour[i] << std::endl;
		}

		std::cout << "3.1.bobJuniour modified -> bobJuniour[i][5] = (char)65 + i;" << std::endl;
		for (unsigned int i = 0; i < 6; i++) {
			bobJuniour[i][5] = (char)65 + i;
		}
		// bobJuniour[0] = "There 0";
		// bobJuniour[1] = "There 1";
		// bobJuniour[2] = "There 2";
		// bobJuniour[3] = "There 3";
		// bobJuniour[4] = "There 4";
		// bobJuniour[5] = "There 5";

		std::cout << "3.2.bobJuniour - > show modification:" << std::endl;
		for (unsigned int i = 0; i < 6; i++) {
			std::cout << bobJuniour[i] << std::endl;
		}

		std::cout << "3.3.bob - > show bob is not efected:" << std::endl;
		for (unsigned int i = 0; i < 6; i++) {
			std::cout << bob[i] << std::endl;
		}
	}

	return (0);
}