#include <iostream>

int main(int ac, char **av) {
	if (ac <= 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl), 1;
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << std::endl;
	return 0;
}