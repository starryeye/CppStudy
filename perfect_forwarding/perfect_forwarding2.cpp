#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

//핵심 : 완벽한 전달을 하려면
// -> int&, int&& 버전의 함수를 따로 제공해야한다.

// -> 그런데, 아래 chronometry에는 하나의 문제점이 존재한다.
// -> 다음 소스 참고.
template<typename F>
void chronometry(F f, int& arg) //n
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg) //10
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	std::cout << n << std::endl; //100
}
