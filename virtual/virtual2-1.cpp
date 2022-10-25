#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.
// 
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

	//가상함수의 오버헤드(가상함수 테이블)를 제거하려면..
	//소멸자를 가상함수로 하지말고 protected에 놓아야한다.
protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	Base* p = new Derived;
//	delete p; //BAse 소멸자를 호출해야 하는데, protected 이므로 컴파일 에러
				//의도 : Base* 타입으로는 delete 하지마라..

	delete static_cast<Derived*>(p); //ok
}