#include <iostream>

void goo(int& arg) { arg = 100; }
void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));	//int& 인 arg를 int&로 캐스팅하는 코드
								//필요없는 코드이지만 있어도 된다. (어차피 컴파일 시점에 사라짐)
								// (두개의 템플릿을 하나로 합치기 위함..)
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// forwarding reference 를 사용하면 위 2개의 함수를 자동 생성할수 있습니다.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	//주의 ! 아래 캐스팅은 "rvalue 캐스팅"이 아니다.

	// chronometry 사용시 2번째 인자로
	// lvalue를 전달하면 lvalue로 캐스팅하고
	// rvalue를 전달하면 rvalue로 캐스팅한다.
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); //std::forward 함수는 위와 같은 캐스팅을 수행한다.
							//C++ 표준
}

int main()
{
	int n = 10;

	chronometry(goo, n); //T=int&, T&&=int& &&, chronometry( int& arg)
							//결정 : static_cast<int&>(arg)
	chronometry(hoo, 10);//T=int, T&&=int&&, chronometry(int&& arg)
							//결정 : static_cast<int&&>(arg)

	std::cout << n << std::endl;
}




