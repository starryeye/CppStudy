#include <iostream>

void goo(int& arg) { arg = 100; }
void hoo(int&& arg) {}


// F.19: For “forward” parameters, 
//       pass by TP&& and only std::forward the parameter

// 전달 받은 인자를 다른 함수에 완벽하게 전달하려면
// 1. 인자를 받을 때 forwarding  reference(T&&) 사용
// 2. 인자를 다른곳에 보낼때 "std::forward<T>(arg)"로 묶어서 전달.


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//시간기록
	f(std::forward<T>(arg));
	//걸린시간출력
}

int main()
{
	int n = 10;
	chronometry(goo, n);
	chronometry(hoo, 10);

	std::cout << n << std::endl;
}




