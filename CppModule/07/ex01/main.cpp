#include "iter.hpp"

int main(void)
{
	int intArr[] = {1, 3, 5};
	iter<int>(intArr, 3, &func);

	std::cout << std::endl;

	double doubleArr[] = {1.11, 3.33, 5.55};
	iter<double>(doubleArr, 3, &func);

	std::cout << std::endl;

	std::string strArr[] = {"hyeonkim", "ekim", "mijeong"};
	iter<std::string>(strArr, 3, &func);

	std::cout << std::endl;

	return 0;
}