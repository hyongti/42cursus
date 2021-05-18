#include "span.hpp"

Span::Span(unsigned int N): n(N)
{
}

Span::Span(const Span &ref)
{
	*this = ref;
}

Span::~Span()
{
}

Span		&Span::operator=(const Span &ref)
{
	if (this == &ref)
		return *this;
	this->n = ref.n;
	this->vec = ref.vec;
	return *this;
}

void		Span::addNumber(int value)
{
	if (vec.size() >= this->n)
		throw Span::VectorFullException();
	this->vec.push_back(value);
}

void		Span::addNumber(std::vector<int>::iterator begin,
						std::vector<int>::iterator end)
{
	if (this->vec.size() + std::distance(begin, end) > this->n)
		throw Span::VectorFullException();
	this->vec.insert(vec.end(), begin, end);
}

unsigned int	Span::longestSpan()
{
	if (this->vec.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> tmp(this->vec);
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}

unsigned int	Span::shortestSpan()
{
	if (this->vec.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> tmp(this->vec);
	std::sort(tmp.begin(), tmp.end());
	unsigned int ret = *(tmp.begin() + 1) - *tmp.begin();
	for(unsigned int i = 0; i < this->vec.size(); i++)
		ret = std::min(ret,static_cast<unsigned int>(tmp[i + 1]) - static_cast<unsigned int>(tmp[i]));
	return ret;
}

const char*	Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not Enough Numbers");
}

const char*	Span::VectorFullException::what() const throw()
{
	return ("Vector is Full");
}

void			Span::showVector()
{
	for (unsigned long i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
}