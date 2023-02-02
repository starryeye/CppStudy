#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	//1. sizeof(Point) 크기의 메모리 할당
	//2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	//1. 소멸자 호출
	//2. 메모리 해지
//	delete p1;


	//------------------------
	//1.메모리만 할당
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));

	//2. 생성자만 호출
	new(p2) Point(1, 2); // 이미 할당된 p2 메모리에 대해 생성자 호출
							// placement new 라고 부르는 기술
//	std::construct_at(p2, 1, 2); //C++20 부터 가능

	//3. 소멸자만 호출
	p2->~Point(); //C++17 이전
//	std::destroy_at(p2); //C++17 부터 가능

	//4. 메모리만 해지
	operator delete(p2);

}