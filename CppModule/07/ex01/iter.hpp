#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T>
void	func(T const &p)
{
	std::cout << p << std::endl;
}

template <typename T>
void iter(T *arr, int len, void (*f)(T const &ref))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif