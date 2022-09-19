class Point
{
	int x = 0; //C++11 부터 가능한 초기화 문법
	int y = 0;
public:
	Point() {}
	Point(int a) : x(a) {}
	Point(int a, int b) : x(a), y(b) {}
};
//위 코드는 컴파일러가 아래처럼 변경한다.
class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};