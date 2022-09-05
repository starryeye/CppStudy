struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt;

	//& 는 원래 reference 라고 불렀으나.. 잘못된 부름이다.
	//lvalue reference로 불러야함.
	//&& 는 rvalue reference로 불린다.

	// 규칙 1. non const lvalue reference로는 lvalue만 가리킬수 있다.
	Point& r1 = pt;			//ok
	Point& r2 = Point();	//error, 임시객체 (rvalue)는 안됨.

	// 규칙 2. const lvalue reference로는 lvalue, rvalue 모두 가리킬수 있다.
	const Point& r3 = pt;		//ok
	const Point& r4 = Point();	//ok

	//규칙 1, 2 까지는 C++98
	//==========================C++98=====================


	//==========================C++11=====================

	//C++ 11에서는 "상수성 없이 임시객체를 가리키는 것" 이 필요 했다..

	// 규칙 3. C++11에서 나온 "rvalue reference"는 rvalue만 가리킵니다.
	Point&& r5 = pt;		//error
	Point&& r6 = Point();	//ok, 임시객체를 가리킬수 있다. 


	//참고. const rvalue reference는 rvalue만 가리키는데..
	//거의 사용하지 않는다.
	//&& 는 move 때문에 주로 사용하는데, const는 move될 수 없다.
	const Point&& r7 = pt;		//error
	const Point&& r8 = Point();	//ok, 임시객체를 가리킬수 있다. 
}