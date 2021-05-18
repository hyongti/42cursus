// iterator를 사용할수있는 mutantstack 만들기 (stack을 상속받음)
// 과제에서 주어진 메인문이 되도록 mutantstack 만들기

#include "mutantstack.hpp"
#include "mutantstack.cpp"
#include <iostream>

int main()
{
	// std::stack<int>	mstack;

	// mstack.push(5);
	// mstack.push(17);

	// std::cout << mstack.top() << std::endl;

	// mstack.pop();

	// std::cout << mstack.size() << std::endl;

	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);

	// std::stack<int>::iterator it = mstack.begin();
	// std::stack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);
	// return 0;



	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;

	


	// MutantStack<char>	ms;
	
	// for(char i='a'; i<='z'; i++)
	// 	ms.push(i);
	// for(MutantStack<char>::iterator it=ms.begin(); it!=ms.end(); it++)
	// 	std::cout<<*it<<' ';
}