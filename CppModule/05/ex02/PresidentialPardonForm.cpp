#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("Presidential Pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	: Form(ref), target(ref.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this == &ref)
		return (*this);
	Form::operator=(ref);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;

	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}