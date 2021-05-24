#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
private:

public:
	Replace();
	~Replace();
	std::string	ReplaceStr(const std::string &filename, const std::string &from, const std::string &to);
};

#endif