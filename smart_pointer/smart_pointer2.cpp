// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 핵심 : 스마트 포인터를 사용한다면..
	//			std::make_shared 로 만들어서 사용하자..

	//아래 코드는 new 를 2번 하게 된다.
	//1. 사용자가 만든 new Point(1,2)
	//2. shared_ptr 생성자에서 new 관리객체
//	std::shared_ptr<Point> sp1(new Point(1, 2)); //bad
									//Point 동적할당한 것을
									//sp1에 힙 메모리 주소 넘김.
									//shared_ptr은 관리객체가 존재한다.
									//관리하는 힙메모리 주소를 가지는 포인터가 몇개인지 기록해놓고..
									//다른데서쓰고있는데 delete하는 상황.. 등을 방지함.
									// 여기 코드에서는 new를 재정의 했다..
									//-> Point 를 new, 관리 객체 new : new는 총 2회이다.

	//아래 코드는 new를 한번한다.
	//1. make_shared() 안에서 new sizeof(Point) + sizeof(관리객체) //Point와 관리객체가 한묶음..
	//																//메모리 파편화 X, 효율성 up
	//2. 그리고 Point 생성자를, 1, 2를 가지고 호출 - 완벽한 전달
	//3. 해당 객체를 가리키는 shared_ptr을 만들어서 반환
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);
}
