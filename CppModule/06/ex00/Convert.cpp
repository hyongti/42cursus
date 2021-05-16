#include "Convert.hpp"

std::string	Convert::special[8] = {
	"inf", "+inf", "-inf", "nan",
	"inff", "+inff", "-inff", "nanf"
};

Convert::Convert(char *input)
{
	this->input = input;
	this->atofInput = 0;
}

Convert::Convert(const Convert &ref)
{
	*this = ref;
}

Convert::~Convert()
{
}

Convert		&Convert::operator=(const Convert &ref)
{
	this->input = ref.input;
	this->atofInput = ref.atofInput;
	return (*this);
}

void		Convert::checkValidInput(void)
{
	int i = -1;
	int count = 0;
	int	countF = 0;

	for (int j = 0; j < 8; j++)
	{
		if (this->special[j] == static_cast<std::string>(this->input))
		{
			this->atofInput = atof(input);
			return ;
		}
	}
	if (strlen(input) > 1)
	{
		while (input[++i])
		{
			if (!(input[i] >= '0' && input[i] <= '9'))
			{
				if (input[i] != '.' && input[i] != 'f')
					throw "argv[1] is invalid";
				if (input[i] == '.')
					++count;
				if (input[i] == 'f')
					++countF;
			}
		}
		if (count > 1 || countF > 1)
			throw "argv[1] is invalid";
		if (countF == 1 && input[i - 1] != 'f')
			throw "argv[1] is invalid";
	}
	this->atofInput = atof(input);
	return ;
}

void		Convert::toChar(void)
{
	int		checkInt;

	checkInt = static_cast<int>(this->atofInput);
	std::cout << "char: ";
	try {
		if (this->atofInput - checkInt != 0)
			throw Convert::ImpossibleException();
		if (!(this->atofInput >= 32 && this->atofInput <= 126))
			throw Convert::NonDisplayableException();
		std::cout << static_cast<char>(this->atofInput) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void		Convert::toInt(void)
{
	std::cout << "int: ";
	try {
		if (this->atofInput > INT_MAX || this->atofInput < INT_MIN)
			throw Convert::ImpossibleException();
		std::cout << static_cast<int>(this->atofInput) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void		Convert::toFloat(void)
{
	int		checkInt;

	checkInt = static_cast<int>(this->atofInput);
	std::cout << "float: ";
	if (isnan(this->atofInput) || isinf(this->atofInput))
		std::cout << this->atofInput << std::endl;
	else if (checkInt - this->atofInput == 0)
		std::cout << this->atofInput << ".0f" << std::endl;
	else
		std::cout << this->atofInput << "f" << std::endl;
}

void		Convert::toDouble(void)
{
	int		checkInt;

	checkInt = static_cast<int>(this->atofInput);
	std::cout << "double: ";
	if (isnan(this->atofInput) || isinf(this->atofInput))
		std::cout << this->atofInput << std::endl;
	else
	{
		std::cout << this->atofInput;
		if (checkInt - this->atofInput == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

const char*	Convert::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char*	Convert::ImpossibleException::what() const throw()
{
	return ("Impossible");
}