#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToExecute;
	const int			gradeToSign;
public:
	Form(std::string const &name, int gradeToExecute, int gradeToSign);
	Form(const Form &ref);
	~Form();
	Form	&operator=(const Form &ref);

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		beSigned(Bureaucrat& ref);

	virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream&	operator<<(std::ostream &os, const Form &ref);

#endif
