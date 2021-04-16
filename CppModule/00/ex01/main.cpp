#include "phonebook.hpp"

int		main(void)
{
	std::string	cmd;
	phonebook	phonebook;

	phonebook.PrintWelcome();
	while (1)
	{
		phonebook.PrintPrompt();
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (-1);
		if (cmd == "ADD")
			phonebook.AddContact();
		else if (cmd == "SEARCH")
			phonebook.SearchContact();
		else if (cmd == "EXIT")
		{
			phonebook.PrintExit();
			return (0);
		}
		else
			phonebook.PrintError();
	}
}