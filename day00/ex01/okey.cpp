#include <iostream>
#include <string>

class Contact
{
	public:
		std::string first;
		std::string last;
		std::string nick;
		unsigned int number;
		std::string secret;

		void print_empty(std::string str)
		{
			if (str.empty()) std::cout << "Information can not be empty" << std::endl;
		}
		
		int add()
		{
			while (first.empty())
			{
				std::cout << "First name :" << std::endl;
				getline(std::cin, first);
				print_empty(first);
			}

			while (last.empty())
			{
				std::cout << "Last name :" << std::endl;
				getline(std::cin, last);
				print_empty(last);
			}

			while (nick.empty())
			{
				std::cout << "Nickname :" << std::endl;
				getline(std::cin, nick);
				print_empty(nick);
			}

			while (secret.empty())
			{
				std::cout << "Darkest secret :" << std::endl;
				getline(std::cin, secret);
				print_empty(secret);
			}			
			while (!number)
			{
				std::cout << "Phone number :" << std::endl;
				std::cin >> number;
				if (!number) std::cout << "Number can't be empty" << std::endl;
			}	
			std::cout << "Contact saved." << std::endl;
			return 0;
		}
};

int main()
{
	Contact mycontact;
	mycontact.add();
	return 0;
}
