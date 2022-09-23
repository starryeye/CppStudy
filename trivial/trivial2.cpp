#include <iostream>
#include <type_traits> 

class Test
{
	int data;
public:
	virtual void foo() {} //가상함수가 있으면 생성자가 trivial 하지 않음

	void goo() {} // 일반 맴버함수만 있으면 생성자는 trivial 하다.

	Test() {} //사용자가 생성자를 제공하면 trivial 하지 않음.

	Test() = default; //컴파일러가 다 안다.
						//trivial 하다.
						//만약 int data = 0;라고 하면..
						//trivial 하지 않음, (생성자에서 초기화 할것이므로)
};

int main()
{
	// trivial 여부를 조사하는 방법
	bool b1 = std::is_trivially_default_constructible<Test>::value; //C++11
	bool b2 = std::is_trivially_default_constructible_v<Test>; //C++17

	std::cout << b2 << std::endl;
}