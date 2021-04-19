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
		std::cout << "----------------Add Contact----------------" << std::endl;
		contact[num].InputInfo();
		++num;
	}
}

void	phonebook::SearchContact()
{
	std::string idx_str;

	std::cout << "--------------Search  Contact--------------" << std::endl;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout.setf(std::ios::right);
		std::cout << std::setw(10) << i << "|";
		contact[i].PreviewInfo();
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "write index : ";
	std::getline(std::cin, idx_str);
	if (std::cin.eof())
		exit(-1);
	else if (idx_str[0] >= '0' && idx_str[0] <= '9' && idx_str[1] == '\0')
	{
		if (atoi(idx_str.c_str()) > num - 1)
			std::cout << "wrong index" << std::endl;
		else
			contact[atoi(idx_str.c_str())].ViewInfo();
	}
	else
		std::cout << "wrong index" << std::endl;
}

void	phonebook::PrintError(void)
{
	std::cout << "wrong command, you can write ADD, SEARCH, EXIT\n" << std::endl;
}

void	phonebook::PrintExit(void)
{
	std::cout << "* * * * * * *  Good Bye  * * * * * * * " << std::endl;
}


