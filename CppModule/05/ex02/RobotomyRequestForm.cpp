#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("Robotomy Request", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	: Form(ref), target(ref.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this == &ref)
		return (*this);
	Form::operator=(ref);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;

	std::cout << "* rizzz...bzzz... *" << std::endl;
	int	percentage = rand();
	if (percentage % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " robotomization has failed." << std::endl;
}