#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 문자열로 반환하는 멤버 함수
	// -> C#, Java 등의 언어에서 널리 사용되는 멤버 함수.
	// -> 상수 객체(const Point p(1, 2)) 도 toString() 호출 가능해야 한다.
	// -> 따라서, 상수 멤버함수로 해야한다. const
	const char* toString() const
	{
		static char s[32];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};
int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

