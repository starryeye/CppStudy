#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	//상수 맴버 함수의 특징
	void print() const
	{
		x = 10;			// error 1. 상수 멤버함수는 멤버데이터 수정이 안된다.
		set(10, 20);	// error 2. 상수 멤버함수는 상수 멤버함수만 호출 가능하다.
		int* p = reinterpret_cast<int*>(this); // error
		const int* ptr = reinterpret_cast<const int*>(this); // ok
						// print()일때, this의 자료형은 Point* 입니다.
						// print() const일때, this는 const Point 입니다.
						// 즉, 상수 멤버 함수에서는 this의 타입이 다르다.

		std::cout << x << ", " << y << std::endl;
	}

	//4. 동일이름의 상수/비상수 멤버 함수를 동시에 제공가능하다.
	void print()
	{
		std::cout << "non const print" << std::endl;
	}
};

int main()
{
	Point p(1, 2);	//비상수 객체는 "상수 멤버함수와 비상수 멤버함수 모두 호출 가능
	p.print();		// 1. "print()" 호출.. 없다면?
					// 2. "print() const" 호출..

	const Point cp(1, 2); // 상수 객체는 상수 멤버 함수만 호출가능
	cp.print();		// "print() const" 만 호출가능
}