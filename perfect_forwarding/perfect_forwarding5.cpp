#include <iostream>

void hoo(int&& arg) {}

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry						hoo(int&&)
//hoo(10) ----------------------------------------------> ok		//바로 보내면 문제없다.
//chronometry(10) ---> int&& arg = 10								//갑자기 이름이 생김 (-> lvalue가됨)
//						hoo(arg) ----------------------> error		//그래서 에러
//						hoo(static_cast<int&&>(arg) ---> ok			//다시 rvalue로 바꿔서 전달.

template<typename F>
void chronometry(F f, int&& arg)
{
	//f(arg);//error
	f(static_cast<int&&>(arg)); //ok
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);
}
