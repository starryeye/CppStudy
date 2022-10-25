// F50 ~ F54 - 람다 표현식 사용한 관한 코딩 관례
// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)
// F.52 : Prefer capturing by reference in lambdas that will be used locally, including passed to algorithms
// F.53 : Avoid capturing by reference in lambdas that will be used non - locally, including returned, stored on the heap, or passed to another thread
// F.54 : If you capture this, capture all variables explicitly(no default capture)

#include <iostream>

// 함수 객체(function object)
// -> () 연산자를 재정의해서 함수처럼 사용가능한 객체
// -> functor 라고도 한다.
// -> 요즘에는 "callable object" 라는 용어도 사용

// add() 함수를 만들면 되는데.. 왜 ?? 함수 객체를 사용하나요..?
// -> 다음예제에서..

struct plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	plus p; //p는 함수가 아닌 객체이다.
	int n = p(1, 2); //객체인 p를 함수 처럼 사용한다.
						//괄호 연산자가 재정의 된것.
						//p.operator()(1,2) 처럼 호출된다.

	int n1 = p.operator()(1, 2); //ok, 이렇게도 사용가능하다.
}