#include <iostream>
#include <vector>

struct Point
{
	int x, y;

	Point(int a, int b) :x(a), y(b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//아래 방법 1, 2, 3 을 직접 실행 해보며 알아보기..
int main()
{
	std::vector<Point> v;

	// vector 에 Point 객체를 넣는 방법

	// 방법 1. 객체를 생성한후 넣기
	// 밑줄 이후 소멸자 2회 호출됨.. 왜 2회인가 생각(생성자는 왜..?)
//	Point pt(0, 0);
//	v.push_back(pt);	//pt를 복사해서 vector에 넣는다.
						//pt 자체를 보관하는 것이 아니라..
						//버퍼(vector)에 pt의 복사본을 만들어 보관
	

	// 방법 2. 임시객체 형태로 전달
	// 소멸자 밑줄전에 1회 호출됨(임시객체 파괴), 밑줄 이후 1회 호출됨.
//	v.push_back(Point(0, 0)); //역시 임시객체의 복사본을 보관한다..

	// 방법 3. 핵심
	// -> 객체를 전달하지 말고, 객체를 만들기 위한 생성자 인자를 전달하자..
	v.emplace_back(0, 0); // emplace_back 이 0,0 을 받아서
							//내부적으로 new Point(0,0) 으로 객체 생성
							//임시객체가 생성되지 않는다..
							//방법 1, 2에 복사본 생성될 시점에 객체가 1회 생성됨.
							//emplace_back은 인자를 받아서.. 0,0을 생성자로 완벽한 전달을 한다.(foward)
							//stl 정의부를 보자..
	std::cout << "------------" << std::endl;
}

//STL 컨테이너에 저장시
//1. primitive 타입이나 포인터를 저장할때는
//	push_xxx() 계열 함수를 사용하거나 emplace_xxx() 함수를 사용하면 된다.
//2. user define 타입을 값으로 저장할때는
//  push_xxx() 사용하지 말고 되도록 emplace_xxx() 사용하자

//push_front() -> emplace_front()
//push_back() -> emplace_back()
//insert() -> emplace()

// emplace에 임시객체를 넣으면..?
// v.emplace_back(0,0) -> new Point(0,0)
// v.emplace_back(Point(0,0)) -> new Point(전달된 인자)
//							  -> new Point(임시객체)
//즉, 1. 임시객체 만들때 생성자 호출
//   2. new Point(임시객체) 에서 move 생성자 호출

// std::shared_ptr<Point> sp = std::make_share<Point>(0,0)
// -> make_shared 가 0, 0 을 받아서 "new Point(0,0)" 하게 된다.
// -> 즉, make_shared 도 완벽한 전달 기술 이다.

// v.emplace_back(std::move(Point(0,0)); // 아래와 동일하다.
// v.emplace_back(Point(0,0));