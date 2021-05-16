#include <cstdlib>
#include <iostream>

struct	Data
{
	std::string s1;
	int n;
	std::string s2;
};

char	randomAlnum()
{
	char alnum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::srand(clock());
	return (alnum[std::rand() % 62]);
}

void	*serialize(void)
{
	char	*ptr = new char[20];

	for(int i = 0; i < 8; i++)
	{
		ptr[i] = randomAlnum();
		ptr[i + 12] = randomAlnum();
	}

	*reinterpret_cast<int*>(ptr + 8) = std::rand();
	return static_cast<void*>(ptr);
}

Data	*deserialize(void *raw)
{
	Data	*data = new Data;
	data->s1 = std::string(static_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	data->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return (data);
}

int main(void)
{
	char	*ptr = static_cast<char*>(serialize());
	Data	*des = deserialize(ptr);

	std::cout << des->s1 << std::endl;
	std::cout << des->n << std::endl;
	std::cout << des->s2 << std::endl;

	delete des;
}