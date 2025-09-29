#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;

	while (1)
	{
		std::string input;

		std::cout << "What do you want to do ? (ADD, SEARCH, EXIT)\n> ";
		std::cin >> input;
		for (int i = 0; input[i]; i++)
			input[i] = std::tolower(input[i]);
		std::cout << "\033[2J\033[H";
		if (input == "add")
		{
			std::string infos[5];
			std::cout << "Enter the new contact information :" << std::endl;
			std::cout << "\tFirst name : "; std::cin >> infos[0];
			std::cout << "\tLast name : "; std::cin >> infos[1];
			std::cout << "\tNickname : "; std::cin >> infos[2];
			std::cout << "\tPhone number : "; std::cin >> infos[3];
			std::cout << "\tDarkest secret : "; std::cin >> infos[4];
			phonebook.addContact(infos);
		}
		if (input == "search")
		{
			std::string index;
			phonebook.displayContacts();
			std::cout << "Enter the contact index you want to display : "; std::cin >> index;
			std::cout << "\033[2J\033[H";
			if (index == "1")
				phonebook.searchContact(1);
			else if (index == "2")
				phonebook.searchContact(2);
			else if (index == "3")
				phonebook.searchContact(3);
			else if (index == "4")
				phonebook.searchContact(4);
			else if (index == "5")
				phonebook.searchContact(5);
			else if (index == "6")
				phonebook.searchContact(6);
			else if (index == "7")
				phonebook.searchContact(7);
			else if (index == "8")
				phonebook.searchContact(8);
			else
				std::cout << "Phonebook can only store 8 contacts !" << std::endl;
		}
		if (input == "exit")
			return 0;			
	}
}