#include "Array.hpp"

int main()
{
	Array<int> test(10);
	try{
		std::cout << test.size() << std::endl;
		std::cout << " index | test[i]" << std::endl; 
		for(unsigned int i = 0;i < test.size();i++)
		{
			test[i] = i + 1;
			std::cout << "   " << i << "   |  ";
			std::cout << test[i] << std::endl;
		}
		std::cout << std::endl;
		Array<int> test2(test);
		std::cout << " index | test2[i]" << std::endl;
		for(unsigned int i = 0;i < test2.size();i++)
		{
			test[i] = i * 2;
			std::cout << "   " << i << "   |  ";
			std::cout << test2[i] << std::endl;
		}
		std::cout << std::endl;
		// 범위를 벗어난 인덱스 출력
		std::cout << test[44] << std::endl;

	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	// const 객체에도 인덱스 접근은 가능
	// const 객체를 반환하는 []연산자 오버로딩을 하지않으면 에러남 
	const Array<double> test3(3);
	for(int i=0; i<3 ; i++)
	{
		test3[i] = i;
		std::cout<< "test3[" << i << "]: " << test3[i] << std::endl;
	}
}