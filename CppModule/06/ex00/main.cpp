#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	Convert convert(argv[1]);
	try
	{
		convert.checkValidInput();
	}
	catch(const char* err)
	{
		std::cerr << err << '\n';
		return 1;
	}
	convert.toChar();
	convert.toInt();
	convert.toFloat();
	convert.toDouble();
	return (0);
}