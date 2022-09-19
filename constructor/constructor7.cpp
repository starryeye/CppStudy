#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }

	//인자가 없는 생성자(디폴트 생성자)가 필요하고,
	// 그 디폴트 생성자내부는 아무 일도 하지 않는다면..

//	Point() {} //이렇게 하지말고..
				//-> 사용자가 생성자를 만든것이다.
				//-> 컴파일러는 이 생성자가 "하는 일이 있다고 생각"한다. (컴파일러는 선언부만 본다.. 구현부 안봄)

	Point() = default; //이렇게 하자.. 이코드가 좋은 코드이다.
						//-> 컴파일러가 생성자를 만들어준다.
						//-> 컴파일러는 생성자가 하는일이 없음(또는 있음)을 정확히 안다.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}