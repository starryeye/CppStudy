#include <iostream>
//2번 복사

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}


void foo(int* p) {}

int main()
{
	// 2번째 인자를 보고 "T" 가 어떤 타입으로 추론될지 생각해보자.
//	chronometry(foo, 0);		//int&& arg = 0 인데 결국
								//foo(arg) 가 되므로 error

	chronometry(foo, nullptr);  // std::nullptr_t&& arg = nullptr;
								//foo(arg)인데
							//std::nullptr_t 타입은 모든 종류의 포인터로 변환가능
							//ok..
}

//컴파일러는 0이 int 타입인걸 알고있다.