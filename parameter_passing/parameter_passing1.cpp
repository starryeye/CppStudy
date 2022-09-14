// F16 ~ F20  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters

#include <iostream>
#include <string>

struct Rect
{
	int left, top, right, bottom;
};

// call by value의 단점.
// 1. 복사본 때문에 메모리(스택) 낭비
// 2. 복사 생성자 호출 <--- std::string 같은 경우.. 이부분에서 
//							오버헤드가 크다.(복사 생성자에서 메모리 깊은 복사)
// 3. 소멸자 호출

void f1(Rect rc) 
{
}
void f2(std::string s2) 
{
}

// call by non-cost reference
// -> 인자값을 수정할때만 사용
// -> 인자를 수정하지 않으면 꼭 const 붙여야한다.(temporory 전달 가능하도록)
void f3(Rect& rc) {}

void f4(const Rect& rc) {} // temporary(rvalue)도 가능해졌다.


int main()
{
	Rect rc;
	f1(rc);

	f3(rc); //ok
	f3(Rect()); // error.. (temporary 불가능)
	f4(Rect()); //ok

	std::string s1 = "to be or not to be";
	f2(s1);
}
