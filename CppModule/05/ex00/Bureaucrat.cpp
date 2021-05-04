#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref): name(ref.getName()), grade(ref.getGrade())
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this == &ref)
		return (*this);
	this->grade = ref.getGrade();
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::upGrade()
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void		Bureaucrat::downGrade()
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
	return (os);
}
