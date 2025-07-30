#include <iostream>
#include <cctype>

int main(int argc, char **argv) {

	if (argc >= 2) {

		for (int i = 1; i < argc; i++)	{
			char *str = argv[i];

			for (int j = 0; str[j] != '\0'; j++) {
				char c = str[j];
				c = std::toupper(c);
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
