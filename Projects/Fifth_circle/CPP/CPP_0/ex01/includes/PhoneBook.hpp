#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;
		int		_count;
	public:
		PhoneBook() {
			_index = 0;
		}

		void	addContact(std::string* infos) {
			_contacts[_index].create(infos);
			_index++;
			_count++;
			if (_index >= 8)
				_index = 0;
		}

		void	searchContact(int index) {
			_contacts[index - 1].display();
		}

		void	displayContacts() {
			std::cout << "  ___NAME_____LASTNAME___NICKNAME____NUMBER__ " << std::endl;
			for (int i = 0; i < 8; i++)
			{
				std::cout << i + 1 << "|"; _contacts[i].getInfos("first_name");
				std::cout << "|"; _contacts[i].getInfos("last_name");
				std::cout << "|"; _contacts[i].getInfos("nickname");
				std::cout << "|"; _contacts[i].getInfos("phone_number");
				std::cout << "|" << std::endl;
				if (i + 1 == 8)
					std::cout << " '-------------------------------------------'" << std::endl;
				else
					std::cout << " |-------------------------------------------|" << std::endl;
			}
		}

		~PhoneBook() {}
};
