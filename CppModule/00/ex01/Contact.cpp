#include "contact.hpp"

std::string		contact::infoname[11] =
{
	"first name",
	"last name",
	"nickname",
	"login",
	"postal address",
	"email address",
	"phone number",
	"birthday date",
	"favorite meal",
	"underwear color",
	"darkest secret"
};

void			contact::InputInfo(void)
{
	for (int i = 0; i < 11; i++)
	{
		std::cout.setf(std::ios::left);
		std::cout << std::setw(15) << infoname[i] << " : ";
		std::getline(std::cin, information[i]);
	}
}

void			contact::PreviewInfo(void)
{
	for (int i = 0; i < 3; i++)
	{
		if (information[i].length() > 10)
		{
			for (int j = 0; j < 9; j++)
				std::cout << information[i][j];
			std::cout << ".";
		}
		else
		{
			std::cout.setf(std::ios::right);
			std::cout << std::setw(10) << information[i];
		}
		if (i < 2)
			std::cout << "|";
	}
	std::cout << "\n";
}

void			contact::ViewInfo(void)
{
	for (int i = 0; i < 11; i++)
	{
		std::cout.setf(std::ios::left);
		std::cout << std::setw(15) << infoname[i] << " : ";
		std::cout << information[i] << std::endl;
	}
}