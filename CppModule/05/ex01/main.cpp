#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
	Form 		*f1;
	try
	{
		f1 = new Form("f1", 0, 10);  // 1등급보다 높아서 예외처리
	}
	catch(const std::exception &e)
	{
		std::cout<<e.what()<<'\n';
	}

	Bureaucrat	b("b", 50);  // 50등급
	Form 		f2("f2", 60, 10);  // 60등급부터 sign가능
	Form 		f3("f3", 40, 10);  // 40등급부터 sign가능
	try
	{
		b.signForm(f2);  // 60등급보다 높은 50등급이라 sign 가능
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b.signForm(f3);  // 40등급보다 낮은 50등급이라 예외처리
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
    return 0;
}