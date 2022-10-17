#include <iostream>

void hoo(int&& arg) {}

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); //ok
	chronometry(hoo, 10); //hoo(10)의 의미 이므로 되어야 한다.
							//그러나 에러이다.
							//그 이유는?
							//해결은 완벽한전달4.cpp
}
