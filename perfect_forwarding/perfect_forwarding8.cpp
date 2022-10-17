#include <iostream>

// 핵심 1. T& 와 T&& 의 의미를 명확히 하자.
// T&  : lvalue만 받겠다는 의미.
// T&& : lvalue와 rvalue를 모두 받겠다는 의미

template<typename T>
void foo(T&& arg)
{
	// 핵심 2. std::move 와 std::forward 의 차이점을 명확히 하자.
	int n1 = std::move(arg); //arg를 항상 rvalue로 캐스팅 (move 생성자를 부르기위해 쓰는 것이기 때문..)

	int n2 = std::forward<T>(arg); //foo 호출 시 인자를 보낼 때
									//rvalue를 보냈으면 rvalue
									//lvalue를 보냈으면 lvalue로 캐스팅..

	//std::move()	 : move 생성자를 호출하고 싶을 때 사용
	//std::forward	 : 인자를 다른 곳에 보내고 싶을 때 사용
}

int main()
{
	int n1 = 10;

	foo(10);
	foo(n1);
}