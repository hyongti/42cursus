#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class FailedToFoundError: public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Failed to Found.");
	}
};

template<typename T>
typename T::iterator easyfind(T t, int value)
{
	typename T::iterator it = std::find(t.begin(), t.end(), value);
	if (it == t.end())
		throw FailedToFoundError();
	std::cout << *it << " was found\n";
	return (it);
}

#endif