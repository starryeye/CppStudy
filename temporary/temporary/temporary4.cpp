#include <iostream>

//--------------------------------
// Temporary(임시객체) 의 특징
// 함수 인자
// 함수 반환
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

/*
//함수 반환값과 임시객체!
void f1(Point  pt) {} //call by value, 복사본 생성됨
void f2(Point& pt) {} //call by reference. 복사본 없음

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/

//-----------------------------------
Point pt(1, 2); //전역변수 pt

Point f1()		//return by value, 임시객체(Point)가 생성되어 반환됨.
{
	return pt;	//리턴용 복사본이 만들어진다.
}

Point& f2()		//return by reference, pt자체를 반환한다.
{
	return pt;
}

Point& f3()
{
	Point p(1, 2);
	return p;	//버그이다. 지역변수를 참조로 반환하면 안된다.
				//지역변수 리턴은 값반환만 사용해야한다.
}//<- 지역변수 p 파괴. 파괴되는 것은 리턴하면 안됨.

//참조 반환은 "전역변수, 맴버 데이터, *this, static 지역" 만 하자.
// -> 파괴되지 않는 것만 사용해야 한다.
// F.43: Never (directly or indirectly) return a pointer or a reference to a local object


int main()
{
	f1().x = 10;	//error. 리턴용 임시객체.x = 10
					//임시객체는 등호의 왼쪽에 올수 없다.
					//리턴용 임시객체는 함수 호출 문장의 끝에서 파괴되기 때문

	f2().x = 10;	//ok. pt.x = 10과 동일
}