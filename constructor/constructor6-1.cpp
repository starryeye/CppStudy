#include <iostream>
#include <memory>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

// 객체의 생성과정에서 가상함수를 호출하고 싶다면..
// -> Factory function 을 사용해라.
// -> 많은 라이브러리가 사용하는 기술이다.

struct Base
{
	Base() { }

	virtual void init() { std::cout << "Base::init" << std::endl; }

	//아래 함수가 Factory Function 이다.
	template<typename T>
	static std::unique_ptr<T> Create()
	{
//		T* p = new T(); //객체를 먼저 만들고
		auto p = std::make_unique<T>();
		p->init();		//가상함수를 호출한다.
						//객체를 만든후 호출하므로 가상함수가 제대로 동작한다.
		return p;
	}

	/*
	//아래 함수가 Factory Function 이다.
	template<typename T>
	static T* Create()
	{
		T* p = new T(); //객체를 먼저 만들고
		p->init();		//가상함수를 호출한다.
						//객체를 만든후 호출하므로 가상함수가 제대로 동작한다.
		return p;
	}
	*/
};

struct Derived : public Base
{
	int x;

	Derived() : x(10) {} 

	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; }
};

int main()
{
//	Derived d; // 이렇게 직접 만들지 말고

	auto p = Base::Create<Derived>(); //객체를 만드는 함수(factory 함수) 를 사용하라는 것
}

//JAVA는 어떠한가...?