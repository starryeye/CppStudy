#include <iostream>

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg) // int&& arg = 0
{
	return f(std::forward<T>(arg));
}


void foo(int* p) {}

int main()
{
	int arg = 0;
	
	foo(0); // ok, 0은 int 타입이지만 포인터로 암시적 형변환이 된다.
			// 단, 리터럴 0 만 포인터로 암시적 형변환 가능.
	foo(arg);// error. 0을 가진 정수형 변수는 포인터로 변환 안됨.

//	chronometry(foo, 0); // error. 이 문제 때문에 nullptr 사용하는 것.
	chronometry(foo, nullptr);
}
// 핵심 : 함수가 포인터를 인자로 받을때
//			완벽한 전달을 사용하는 모든 도구들은 0 대신 nullptr 사용하자.
//		std::emplace_back(), std::make_shared(), chronometry()
