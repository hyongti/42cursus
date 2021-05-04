#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
	ShrubberyCreationForm	s("42 cluster");
	Bureaucrat				hyeonkim1("hyeonkim", 130);  // 130등급이라 승인과 실행 둘다 가능
	hyeonkim1.signForm(s);  // 승인가능
	hyeonkim1.executeForm(s);  // 실행가능

	std::cout<<"=======================================\n";
	RobotomyRequestForm r("dog");
	Bureaucrat			hyeonkim2("hyeonkim", 50);  // 50등급이라 승인은 가능하지만 실행은 불가능
	hyeonkim2.signForm(r);  // 승인가능
	hyeonkim2.executeForm(r);  // 실행불가능

	std::cout<<"=======================================\n";
	PresidentialPardonForm p("moon");
	Bureaucrat hyeonkim3("hyeonkim", 30);  // 30등급이라 승인과 실행 둘다 불가능
	hyeonkim3.signForm(p);  // 승인 불가능
	hyeonkim3.executeForm(p);  // 실행 불가능
}