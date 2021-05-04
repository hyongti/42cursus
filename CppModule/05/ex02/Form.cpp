#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int gradeToExecute, int gradeToSign)
	: name(name), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &ref)
	: name(ref.getName()), gradeToExecute(ref.getGradeToExecute()), gradeToSign(ref.getGradeToSign())
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form		&Form::operator=(const Form &ref)
{
	if (this == &ref)
		return (*this);
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return (*this);
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::getSigned() const
{
	return (this->isSigned);
}

int			Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int			Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void		Form::beSigned(Bureaucrat& ref)
{
	if (this->gradeToSign > ref.getGrade())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

std::ostream&	operator<<(std::ostream &os, const Form &ref)
{
	os << ref.getName() << 
		", sign status " << ref.getSigned() << 
		", sign grade " << ref.getGradeToSign() << 
		", execute grade " << ref.getGradeToExecute() << std::endl;
	return (os);
}