#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding
// -> 함수 인자를 다른 함수에 전달하는 것.

// perfect forwarding(완벽한 전달)
// -> 인자를 어떠한 변화도 없이 다른 함수에게 전달 하는 것.
// C++98로는 구현못함.. C++11로 가능

// 특정함수의 수행시간을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, T arg) //전달받은 T arg를 F 로 보낸다.. -> forwarding
{
	//시간 기록
	f(arg);
	//걸린 시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n); //goo(n);

	std::cout << n << std::endl;
}
