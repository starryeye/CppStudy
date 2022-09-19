#include <iostream>

class Point
{
	int x, y;
public:
	//Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};
//Point p; //error. Point 는 디폴트 생성자가 없다..

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
				//컴파일러가 변경한 코드
//	Rect() {}	//Rect() : ptFrom(), ptTo()

	//핵심 : 맴버데이터가 디폴트 생성자가 없는 타입이면 반드시
	//		사용자가 명시적으로 생성자를 호출하는 코드를 제공해야 한다.

	// 방법1. 맴버 초기화 리스트에서 호출
	Rect() : ptFrom(0, 0), ptTo(0, 0) {} // ptTo{0,0} 처럼 {}도 가능(권장, 좀더 안정)

};

class Rect2
{
	//방법 2. C++ 11 부터는 맴버데이터 만들때 인자 전달 가능
	Point ptFrom{ 0,0 };
	Point ptTo{ 0,0 };

//	Point ptTo(0, 0); //error, 여기서는 {}만 가능하다.
						//ptTo라는 함수로 인식해버린것임.
						//인자 전달에 그냥 0을 넣어놔서 에러
};

int main()
{
	Rect r;
}




