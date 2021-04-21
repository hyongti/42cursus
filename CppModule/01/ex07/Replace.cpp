#include "Replace.hpp"

Replace::Replace(void)
{
}

Replace::~Replace()
{
}

std::string	Replace::ReplaceStr(const std::string &filename, const std::string &from, const std::string &to)
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		line;
	std::size_t		pos;

	if (filename.length() == 0 || from.length() == 0 || to.length() == 0)
		return ("Empty Argument");
	else
	{
		input.open(filename);
		output.open(filename + ".replace");
		if (!input.is_open() || !output.is_open())
			return ("Opening File Failed");
		while (getline(input, line))
		{
			while (true)
			{
				pos = line.find(from);
				if (pos == std::string::npos)
					break;
				line.replace(line.find(from), from.length(), to);
			}
			output << line;
			if (!input.eof())
				output << std::endl;
		}
	}
	input.close();
	output.close();
	return ("");
}
