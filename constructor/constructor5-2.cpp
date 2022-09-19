#include <iostream>

int g = 10;

class Point
{
	int x = 0;
	int y = ++g; // 절대로 이런 초기화는 하지 말 것..
public:
	Point() {} // : x(0). y(++g)
	Point(int a) : x(a) {} // : x(a). y(++g)
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1;
	Point p2(0);
	Point p3(0, 0);

	std::cout << g << std::endl;
	//-> ++g는 총 2회 수행됨 g는 12가 출력된다.

	//결론..
	//맴버 변수 초기화는 리터럴 값으로 초기화만 사용해라.


	//결론..
	//맴버변수 초기화는 맴버변수 선언시 바로 초기화 해라.(창시자 가이드)
}