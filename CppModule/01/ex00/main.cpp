#include "Pony.hpp"

void	ponyOnTheHeap(const char *str)
{
	Pony *pony = new Pony(str);
	delete pony;
	//malloc & free로 할당 및 해제할 때에는 생성자 소멸자 호출이 안 됨
}

void	ponyOnTheStack(const char *str)
{
	Pony pony = Pony(str);
}

int		main(void)
{
	std::cout << "\n----- ponyOnTheHeap -----\n";
	ponyOnTheHeap("AAA");
	ponyOnTheHeap("BBB");

	std::cout << "\n----- ponyOnTheStack -----\n";
	ponyOnTheStack("CCC");
	ponyOnTheStack("DDD");

	return (0);
}