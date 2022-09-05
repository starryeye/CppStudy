#include <iostream>

//--------------------------------
// Temporary(임시객체) 란?
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { 
		std::cout << "Point()" << std::endl; 
	}
	~Point() {
		std::cout << "~Point()" << std::endl; 
	}
};
int main()
{
	Point pt(1, 2); //이름 있는 객체 (named object)
					//수명 : 자신을 선언한 블럭을 벗어날때 파괴.

	Point(1, 2);	//이름 없는 객체 (unnamed object)
					//수명 : 자신을 선언한 문장의 끝
					//-> 임시객체(temporary) 라 부른다.

	Point(1, 2), std::cout << "X" << std::endl; // C++에서는 컴마를 붙이고 다음 문장을 적을 수 있다. 
												//실행 순서: 생성자 -> X -> 소멸자(X출력후 문장끝에서 소멸자 호출)

	std::cout << "-------" << std::endl;
} //<-- pt 파괴

//C++ object lifetime.pdf "hurb shutter" 라는 자료도.. 참고하면 좋음, 소멸자