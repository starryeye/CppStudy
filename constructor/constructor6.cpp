#include <iostream>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

// C.82 : Don't call virtual functions in constuctors and destuctors
// 생성자와 소멸자에서는 "가상함수가 동작하지 않습니다." 무조건 자신의 맴버 함수가 호출됩니다..

struct Base
{
	Base() { init(); } // Base의 init 호출

	void foo() { init(); }; //this->init() 인데 이 위치에서 this는 Base* 이다.
							//init()이 가상이 아니면 Base::init() 호출
							//init()이 가상이면 Derived::init() 호출
	//void init() { std::cout << "Base::init" << std::endl; }     // 1
	virtual void init() { std::cout << "Base::init" << std::endl; }     // 해결법
};

struct Derived : public Base
{
	int x;
						//컴파일러가 변경
	Derived() : x(10) {} //Derived() : Base(), x(10) {}
						//컴파일러가 Base()를 먼저 호출한다. (Derived()를 초기화 하기전에..)
						//그래서 초기화 되기 전의 값을 쓸순 없으므로.. 생성/소멸에서 init 함수는 본인 init 함수 콜됨 

	//void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; } // 2
};

int main()
{
	Derived d;
	d.foo();   // 결과 예측해 보세요
}

