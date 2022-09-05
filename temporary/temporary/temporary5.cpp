#include <iostream>

// F.44: Return a T & when copy is undesirable and "returning no object" isn't needed

//--------------------------------
// Temporary(임시객체) 의 특징
// 함수 반환
//--------------------------------

class Counter
{
	int value{ 0 };
public:
	//임시객체 반환
	//return by value
	Counter increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	~Counter() { std::cout << "~Counter" << std::endl; }

};

class Counter2
{
	int value{ 0 };
public:
	//*this를 반환할때는 대부분 참조 반환을 사용해야 한다.
	//*this는 increment() 호출이 종료되어도 파괴되지 않는다.
	//return by reference
	Counter2& increment()
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	~Counter2() { std::cout << "~Counter2" << std::endl; }

};

int main()
{
	Counter c;
	//	c.increment();5
	//	c.increment();
	//	c.increment(); //3이 증가될 것이다. ->실행하면 3나옴.

	std::cout << "----------------" << std::endl;
	c.increment().increment().increment();	//this를 리턴하여 다시 increment() 함수 호출이 가능하도록.. 하였다.
											//3이 나오겠지?
											//-> increment함수는 값반환이다. 즉.. 임시객체이다.
											//-> 3개의 임시객체가 생성되고 파괴되고한다...각각value 1,2,3
											//마지막 세번째 임시객체의 value는 3일 것이지만..
											//결국 c.get의 값은 1로 1이 출력됨.
											//성능에도 문제가 있지만.. 의도하지 않은 로직이 될 가능성도 존재한다.
	std::cout << "----------------" << std::endl;

	std::cout << c.get() << std::endl;


	Counter2 d;

	std::cout << "----------------" << std::endl;
	d.increment().increment().increment();	//this를 리턴하여 다시 호출이 가능하도록.. 하였다.
											//이제 3이 나온다.
											//return by reference로 임시객체가 생성되지 않는다.
	std::cout << "----------------" << std::endl;

	std::cout << d.get() << std::endl;

}//<-- 이름있는 객체 c, d 파괴(소멸자 호출)