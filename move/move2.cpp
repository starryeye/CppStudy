#include <iostream>

struct Point
{
	int x;
	int y;
};

//함수 오버로딩 규칙 - 꼭 기억할 것.
//아래 error아님.. 3개 오버로딩 가능하다.
//lvalue reference
//const lvalue reference
//rvalue reference
void foo(Point& pt) { std::cout << "Point&" << std::endl; } //1번함수
void foo(const Point& pt) { std::cout << "const Point&" << std::endl; }//2번함수
void foo(Point&& pt) { std::cout << "Point&&" << std::endl; }//3번함수

//아래코드도 가능하다.. 하지만 사용하진 않는다.
void foo(const Point&& pt) { std::cout << "const Point&&" << std::endl; }//4번함수

int main()
{
	Point pt;
	foo(pt);		//pt는 lvalue이다.
					//1번 호출, 없으면 2번호출 (상수가 아니므로..) ->우선순위

	foo(Point());	//임시객체이므로 rvalue이다.
					//3번 호출, 없으면 2번호출 (상수가 아니므로..) ->우선순위

	foo(static_cast<const Point&&>(Point())); // 4번 호출

	//결론
	//lvalue, rvalue 를 한개의 함수에서 모두 받아서 처리하고 싶다.
	// -> const lvalue reference 사용.
}