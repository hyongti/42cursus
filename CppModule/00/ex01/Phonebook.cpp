#include "phonebook.hpp"

void	phonebook::PrintWelcome(void)
{
	std::cout << "* * * *  My Awesome PhoneBook  * * * *" << std::endl;
}

void	phonebook::PrintPrompt(void)
{
	std::cout << "Enter your command [ADD, SEARCH, EXIT]" << std::endl;
}

void	phonebook::AddContact(void)
{
	if (num == 8)
	{
		std::cout << "Phonebook is Full !!" << std::endl;
		std::cout << "You can only SEARCH now" << std::endl;
	}
	else
	{
		contact[num].InputInfo();
		++num;
	}
}

void	phonebook::SearchContact()
{
	int	idx;
	std::string str;

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout.setf(std::ios::right);
		std::cout << std::setw(10) << i << "|";
		contact[i].PreviewInfo();
	}
	std::cout << "write index : ";
	std::getline(std::cin, str);
	idx = atoi(str.c_str());
	if (std::cin.eof())
		exit(-1);
	if (idx < 0 || idx >= num || std::cin.fail())
	{
		std::cout << "wrong index" << std::endl;
		std::cin.clear();
	}
	else
	{
		contact[idx].ViewInfo();
		std::cin.clear();
	}
}

void	phonebook::PrintError(void)
{
	std::cout << "wrong command, you can write ADD, SEARCH, EXIT\n" << std::endl;
}

void	phonebook::PrintExit(void)
{
	std::cout << "* * * * * * *  Good Bye  * * * * * * * " << std::endl;
}


