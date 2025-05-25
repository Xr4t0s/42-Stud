#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	// std::string infos[5];

	// infos[0] = "helloworldcjkhdjkd";
	// infos[1] = "world";
	// infos[2] = "test";
	// infos[3] = "+33";
	// infos[4] = "fuckyou";
	// phonebook.addContact(infos);
	// infos[0] = "test";
	// infos[1] = "test";
	// infos[2] = "test";
	// infos[3] = "+test";
	// infos[4] = "test";
	// phonebook.addContact(infos);
	// phonebook.displayContacts();
	// phonebook.searchContact(1);
	while (1)
	{
		std::string input;

		std::cout << "Que souhaitez-vous faire ? (ADD, SEARCH, EXIT)\n> ";
		std::cin >> input;
		if (input == "ADD")
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
		if (input == "SEARCH")
		{
			std::string index;
			phonebook.displayContacts();
			std::cout << "Enter the contact index you want to display : "; std::cin >> index;
			int	i = atof(index);
		}
		if (input == "EXIT")
			
	}
}