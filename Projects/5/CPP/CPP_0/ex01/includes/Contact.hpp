#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

		void	_slice(std::string attr)
		{
			int len = attr.length();
			for (int i = 0; i < 10 - len && i < 10; i++)
				std::cout << " ";
			if (len > 10)
			{
				for (int i = 0; attr[i] && i < 9; i++)
					std::cout << attr[i];
				std::cout << ".";
			}
			else
				std::cout << attr;
		}

	public:
		Contact() {}

		void	create(std::string* infos) {
			_first_name = infos[0];
			_last_name = infos[1];
			_nickname = infos[2];
			_phone_number = infos[3];
			_darkest_secret = infos[4];
		}

		void	display(void) {
			std::cout << "First name\t : " << _first_name << std::endl;
			std::cout << "Last name\t : " << _last_name << std::endl;
			std::cout << "Nickname\t : " << _nickname << std::endl;
			std::cout << "Phone number\t : " << _phone_number << std::endl;
			std::cout << "Darkest secret\t : " << _darkest_secret << std::endl;
			std::cout << std::endl;
		}

		void	getInfos(std::string attr) {
			if (attr == "first_name")
				_slice(_first_name);
			else if (attr == "last_name")
				_slice(_last_name);
			else if (attr == "nickname")
				_slice(_nickname);
			else if (attr == "phone_number")
				_slice(_phone_number);
			
		}

		~Contact() {}
};
