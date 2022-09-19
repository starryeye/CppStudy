#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	//mutable : 상수 멤버 함수 안에서도 값을 수정할 수 있는 맴버 데이터 만들때 사용
	mutable char cache[32];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	//x,y는 변하지 않지만.. 내부 로직상 다른 값들 때문에 const를 못쓸 위기에 처함..
	// -> mutable..
	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
	//x, y 를 변경하는 모든 함수에서 "cache_valid = false 로 변경
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}