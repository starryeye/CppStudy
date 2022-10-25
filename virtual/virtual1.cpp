#include <iostream>

// C.140: Do not provide different default arguments 
//        for a virtual function and an overrider

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo(); // 결과 예측해보자..
				// 결과 : "Derived : 10"
				//
				// 이코드가 컴파일되면
				// p->foo(10) 으로 변경됨.

				// 그런데.. 실제 어떤 foo를 호출할지는 
				// 실행시간에 p가 가리키는 곳의 메모리 조사후 결정

	//핵심
	// 아래 두가지의 문법을 섞지마라..
	//디폴트 인자를 채워주는 것 : 컴파일 시간에 작업
	//어떤 함수를 호출할지 결정(가상함수) : 실행시간에 작업
}