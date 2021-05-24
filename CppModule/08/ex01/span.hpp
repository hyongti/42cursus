#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
private:
	unsigned int n;
	std::vector<int> vec;
	Span();
public:
	Span(unsigned int N);
	Span(const Span &ref);
	~Span();
	Span	&operator=(const Span &ref);

	void	addNumber(int);
	void	addNumber(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	class	VectorFullException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	class	NotEnoughNumbersException: public std::exception
	{
	public:
		const char *what() const throw();
	};
	void	showVector();
};

#endif