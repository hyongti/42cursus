#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat A("A", 1);  // A의 등수 : 1등

	std::cout<<A;  // <<연산자를 오버로딩하여 Bureaucrat 객체가 출력가능
	try
	{
		A.upGrade(); // A의 등수를 1높임 0등이됨 예외가 발생함
	}
	catch(const std::exception& e)  // throw로 던진 클래스를 받음
	{
		std::cout << e.what() << '\n';  // 오버라이딩한 what함수의 반환값 출력
	}

	Bureaucrat *B;
	try
	{
		B = new Bureaucrat("B", 151);
	}
	catch(const std::exception& e)  // throw로 던진 클래스를 받음
	{
		std::cout<<e.what()<<'\n';  // 오버라이딩한 what함수의 반환값 출력
	}
	return 0;
}