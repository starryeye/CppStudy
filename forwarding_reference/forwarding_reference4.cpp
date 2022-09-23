#include <iostream>
template<typename T> void foo(T&& arg)
{
	// 확인하는법
	//1. 아래처럼 typeid()로 확인하지 말것..
	//->typeid는.. &,&&,const, volitile 등이 출력되지 않음
	//std::cout << typeid(arg).name() << std::endl;

	// 실제 생성된 함수의 이름을 출력해서 확인하자.
//	std::cout << __func__ << std::endl; //함수 이름을 담은 C++ 표준 매크로, 진짜 함수이름만 나옴..

	std::cout << __FUNCSIG__ << std::endl; //인자를 포함한 함수 전체 이름
											//C++ 표준 아님..
											//visual studio 만 가능..

	std::cout << __PRETTY_FUNCTION__ << std::endl; //g++, clang++만 가능
													//visual studio 안됨..
}
int main()
{
	int n = 10;

	foo(n);  // T=int&,  생성된 함수: foo(int& arg)
	foo(10); // T=int,	 생성된 함수: foo(int&& arg)
}




