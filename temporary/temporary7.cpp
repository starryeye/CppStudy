#include <iostream>

//--------------------------------
// Temporary(임시객체) 의 특징
// 캐스팅
//--------------------------------

//기반 클래스
struct Base
{
	int value = 10;
};

//파생 클래스
struct Derived : public Base
{
	int value = 20; //기반클래스의 변수이름과 동일하게 파생클래스에서 사용..
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 파생클래스 20이 출력된다.

	std::cout << static_cast<Base&>(d).value << std::endl;	// 기반클래스의 10이 출력된다.

	std::cout << static_cast<Base>(d).value << std::endl;	// 기반클래스의 10이 출력된다.
															// Base 타입의 임시 객체를 d를 복사 하여 만들게됨. 
															// 생성된 임시객체의 value를 출력하게된것.



	static_cast<Base&>(d).value = 30;	//ok
	static_cast<Base>(d).value = 30;	//error. Base 임시객체를 생성한 코드이다.

	//결론. 임시객체는
	//1. 개발자가 의도적으로 만들기도 하고( 대부분 함수 인자 f1(Point(1,2) )
	//2. "값타입으로 반환하는 함수", "값 타입으로 캐스팅" 등을 할 때 생성된다.

	//-> 생성파괴가 이루어지므로 성능저하의 원인이 된다. 
	//-> 생각지도 못한 로직이 될수도 있다.. -> Counter 객체와 같이..temporary5 참조.
}