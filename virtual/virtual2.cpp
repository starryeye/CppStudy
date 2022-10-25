#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.
// 
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
	//Base 소멸자가 virtual이면 Derived 소멸자도 virtual 이된다.
};

int main()
{
//	Derived d;

//	Derived* p = new Derived; //Derived 생성자 호출
//	delete p;				  //Derived 소멸자 호출

	Base* p = new Derived;	  //Derived 생성자 호출
	delete p;		//이 순간 소멸자를 호출 해야한다. Base소멸자만 호출
	
	//컴파일러가 동작하는 방식
	//1. p가 Base* 이므로 Base 클래스에서 소멸자가 가상함수인지 조사
	// -> 소멸자가 가상함수가 아니면, 무조건 Base 소멸자 호출
	// -> 소멸자가 가상함수라면, 컴파일 시간에는 p의 메모리 조사하는 기계어 코드 생성
	//								실행시 조사한 결과에 따라 소멸자 호출
	// -> 따라서.. Base 소멸자에 virtual 키워드 추가해야됨
}