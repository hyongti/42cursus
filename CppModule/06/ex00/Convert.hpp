#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <cstdlib>

class Convert
{
private:
	char*	input;
	static std::string	special[8];
	double	atofInput;
public:
	Convert();
	Convert(char* input);
	Convert(const Convert &ref);
	~Convert();
	Convert	&operator=(const Convert &ref);

	void	checkValidInput();
	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

	class ImpossibleException: public std::exception
	{
		virtual const char *what() const throw();
	};
	class NonDisplayableException: public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif