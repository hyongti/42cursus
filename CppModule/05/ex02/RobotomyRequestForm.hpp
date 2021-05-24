#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string	target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &ref);

	void	execute(Bureaucrat const & executor) const;
};

#endif