// Con.1 : By default, make objects immutable
// -> 기본적으로, 객체는 immutable로 만들어라
// Con.2 : By default, make member functions const
// -> 기본적으로, 맴버함수는 상수로 만들어라
// Con.3 : By default, pass pointersand references to consts
// -> 기본적으로 ??

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() 
	{
		std::cout << x << ", " << y << std::endl;
	}
	//상수 멤버 함수
	// -> 멤버 함수 () 뒤쪽에 const를 붙이는 문법
	// -> 내부적으로 멤버 데이터를 수정하지 않겠다고 컴파일러에게 알려주는것
	// 핵심 : 상수 객체는 "상수 멤버 함수만 호츨 가능"
	void print2() const
	{
//		x = 10; //error
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2); //상수 객체

	//핵심 : pt는 상수 객체 입니다.
	pt.x = 10;		//error. x는 public 이지만, 상수 이므로
					
	pt.set(10, 20);	//error. set 내부에서 변경 중
	pt.print();		//error.
	pt.print2();	//ok, print2() 가 const member function 이면
					//호출 가능

	//참고
	//컴파일러는 선언만 보고 호출 할 수 있는지 없는지를 안다.
	//-> 헤더 파일만 include 해주면 함수 호출이 가능한 이유는 여기에 있다..
}


