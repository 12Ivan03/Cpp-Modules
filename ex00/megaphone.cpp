#include <iostream>

int main(int argc, char **argv) {

	if (argc >= 2) {

		for (int i = 1; i < argc; i++)	{
			char *str = argv[i];

			for (int j = 0; str[j] != '\0'; j++) {
				char c = str[j];

				if (c >= 'a' && c <='z') {
					c -= 32;
				}
				std::cout << c;
			}

			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "You need to add a string" << std::endl;
		return 1;
	}
	return 0;
}
