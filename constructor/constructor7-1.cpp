#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {} // 사용자가 직접 만든 생성자!
	Point() = default; // 컴파일러가 만든 생성자.
};

int main()
{
	int n1;		//쓰레기값
	int n2 = 0; //C++98 스타일
	int n3{ 0 };//C++11 부터 지원, value initialization이라 부름
	int n4{};	//C++11 부터 지원, default initialization이라 부름
				//-> 0으로 초기화 됨.
				//"사용자가 직접 만든 생성자!"가 있다면.. 쓰레기값 초기화..

	Point pt{}; //모든 맴버가 "디폴트값(0)"으로 초기화
				// -> 사용자가 직접만든 생성자 없을 때.
				// -> 컴파일러가 만든 생성자라면 해줌.
	std::cout << pt.x << " " << pt.y << std::endl; //0
}
// www.godbolt.org 에 접속해보자..
// -> 다양한 언어의 "어셈블리코드"를 확인 할 수 있는 사이트.


//-> godbolt에서.. 아래 코드 ..
/*
struct Point
{
	int x = 0;
	int y;

	//	Point() {} // 사용자가 직접 만든 생성자!
	Point() = default; // 컴파일러가 만든 생성자.
};

int main()
{
	Point pt;
}
// www.godbolt.org 에 접속해보자..
// -> 다양한 언어의 "어셈블리코드"를 확인 할 수 있는 사이트.
*/