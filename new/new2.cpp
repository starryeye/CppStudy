#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없습니다.
//	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개 만들어 보세요 (메모리가 연속적인..)
//	Point* p2 = new Point[10]; // 디폴트 생성자를 10번 호출하는 표기법
								//그런데, 디폴트 생성자가 없다..
	
	//메모리 할당과 생성자 호출을 분리하면 아주 유연하게 코딩 할 수 있다.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10)); //10개의 메모리 할당

	//10개의 메모리 공간에 10개의 객체를 생성(생성자를 호출한다는 의미)
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0); //std::construct_at(&p2[i], 0, 0);
	}

	//.....
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point(); //std::destroy_at(&p2[i]);
	}

	operator delete(p2);
	
}