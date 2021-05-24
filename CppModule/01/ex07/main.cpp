#include "Replace.hpp"

int		main(int argc, char *argv[])
{
	std::string	result;
	Replace		replace;

	if (argc != 4)
	{
		std::cout << "invalid number of arguments" << std::endl;
		return (1);
	}
	result = replace.ReplaceStr(argv[1], argv[2], argv[3]);
	if (result.length() != 0)
	{
		std::cout << result << std::endl;
		return (1);
	}
	std::cout << "Replace Successed" << std::endl;
	return (0);
}