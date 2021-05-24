#include "span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(-2147483648);
	sp.addNumber(2147483647);
	std::cout << "shortest span" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longest span" << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span test(10000);
	std::vector<int> vec;
	
	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100);
	
	test.addNumber(vec.begin(), vec.end());
	test.showVector();
	
	std::cout << "shortest span" << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << "longest span" << std::endl;
	std::cout << test.longestSpan() << std::endl;

	return 0;
}