#include <iostream>

//--------------------------------
// Temporary(임시객체) 의 특징
// 함수 인자
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// temporory와 함수 인자.
void foo(const Point& pt) {}	//인자로 포인트 객체를 요구.
								//임시객체를 받을수 있다.
								//const는 안정성의 의도도 있지만.. temporory를 받을수 있게하는 의도도 있는것이다.
void goo(Point& pt) {}			//const없음, 의도 : 인자로 받은 객체를 수정하고 싶음
								//임시객체를 받을 수 없다.

int main()
{
	Point pt(1, 2); //이름 있는 객체
	foo(pt); //인자로 포인트 객체를 넣음


	
	foo(Point(1, 2));	//전달후, 임시객체 바로 파괴
						//함수 인자로만 사용할 객체가 필요하면
						//temporary 형태로 전달하는 것이 좋다.



	goo(Point(1, 2));	//임시객체를 전달했는데..
						//바로 파괴될 것임.. 근데 const를 안붙여놨으니..
						//수정을 하겠다는 의도.. -> 말이 안됨.
						//즉.. temporory는 const로 받고 복사해서 수정해라..

	std::cout << "-----" << std::endl;
}// <- 이름있는 객체 소멸자 불리는 시점.





