#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	virtual ~Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &ref);

	std::string	getName() const;
	int			getGrade() const;
	void		upGrade();
	void		downGrade();
	void		signForm(Form& ref);
	void		executeForm(Form const & ref);

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat &ref);

#endif