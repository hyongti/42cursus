#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm: public Form
{
private:
	std::string	target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &ref);

	void	execute(Bureaucrat const & executor) const;
};

#endif