#include <iostream>

//--------------------------------
// Temporary(임시객체) 의 특징
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	//임시객체(temporary) 특징
	Point pt(1, 2);



	pt.x = 10;					//ok
	Point(1, 2).x = 10;			//error, 임시객체는 등호의 왼쪽에 올수 없다.
								//임시객체는 보통 "rvalue" 라고 말함

//	Point(1, 2).set(10, 20);	//set 함수가 있다면 이코드는 된다.
								//즉, 임시객체가 상수는 아님.



	Point* p1 = &pt;			//ok
	Point* p2 = &Point(1, 2);	//error. 임시객체는 주소 연산자로 주소를 구할수 없다.(문법상..)
								//단, 생성자에서 this는 사용가능(즉, 주소가 있긴하다는것)




	Point& r1 = pt;				//ok
	Point& r2 = Point(1, 2);	//error. 참조로 가리킬수 없다.




	const Point& r3 = Point(1, 2);	//ok. 임시객체는
									// const reference(상수 참조)로 가리킬 수 있다.
									//이제, 임시객체의 수명은 r3의 수명으로 연장이됨.
									//이름없는 객체에 이름을 부여하게된 것이다.
	r3.x = 10; // 하지만.. 상수참조이므로 객체 수정은 안된다.


	//C++11 만들때, 임시객체를 상수성 없이 가리키고 싶었다.
	//move와 완벽한 전달을 위해서..
	Point&& r4 = Point(1, 2); //ok. 상수성 없이 임시객체 가리키기.. 여기서의 "&&" 가 "rvalue reference" 이다.

}







