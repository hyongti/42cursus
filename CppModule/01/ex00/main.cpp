#include "Pony.hpp"

void	ponyOnTheHeap(const char *str)
{
	Pony *pony = new Pony(str);
	delete pony;
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