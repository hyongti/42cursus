#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>

template <typename T>
class Array
{
private:
	T	*_arr;
	unsigned int	_size;
public:
	Array(): _arr(NULL), _size(0)
	{
	}
	Array(unsigned int n): _arr(new T[n]), _size(n)
	{
	}
	Array(const Array &ref)
	{
		*this = ref;
	}
	~Array()
	{
		delete[] _arr;
	}
	Array	&operator=(const Array &ref)
	{
		if (this == &ref)
			return (*this);

		delete[] _arr;
		_arr = new T[ref._size];
		_size = ref._size;
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = ref._arr[i];
		return *this;
	}
	T	&operator[](unsigned int idx)
	{
		if (idx >= _size)
			throw OutOfRangeException();
		return (_arr[idx]);
	}
	const T	&operator[](unsigned int idx) const
	{
		if (idx >= _size)
			throw OutOfRangeException();
		return (_arr[idx]);
	}
	unsigned int	size() const
	{
		return (this->_size);
	}
	class OutOfRangeException: public std::exception
	{
	private:
		virtual const char* what() const throw ()
		{
			return ("Index Exception: out of range");
		}
	};
};

#endif