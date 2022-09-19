#include <iostream>

// 생성자 호출순서 를 알아 두세요.
// 절대로!! 실행결과를 보고 예측하지 말것..
// "정확한 문법을 이해하고, 실행결과를 보자.."

struct BM //BM : Base Member
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM //DM : Drived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;

	// 사용자 코드		// 컴파일러가 변경한 코드
	Base()				// Base() : bm()
	{
		// call BM::BM() 의 기계어 코드 생성 ( C++ 코드로 표현할때는 위 초기화 리스트에 표기)

		std::cout << "Base()" << std::endl;
	}
	~Base() 
	{ 
		std::cout << "~Base()" << std::endl; 

		//소멸자는 ~Base()안의 모든 문장을 실행후에 맴버의 소멸자를 호출
		// ~bm()
	}
};

struct Derived : public Base
{
	DM dm;
	
	//핵심 1. 컴파일러가 만들어주는 코드를 이해하자..
	// 사용자 코드		//컴파일러가 변경한 것.
//	Derived()			//Derived() : Base(), dm()

	//핵심 2. 사용자가 기반클래스나, 맴버데이터 생성자를
	// 명시적으로 호출 할 수는 있지만..
	// 생성자 호출 순서는 절대 변경 할 수 없다.
	// -> 항상, 맴버 데이터 보다, 기반 클래스 생성자가 먼저 불림.
	Derived() : dm(), Base()
	{
		std::cout << "Derived()" << std::endl;
	}
	~Derived() 
	{ 
		std::cout << "~Derived()" << std::endl; 

		//~dm()
		//~Base()
	}
};

int main()
{
	Derived d; // 이 순간의 결과를 예측해 보세요.
				// call Derived::Derived()
				//컴파일러가 초기화 리스트를 만들어줌..
				// 초기화 리스트 먼저 부름.
}
