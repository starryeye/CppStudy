#include <iostream>
#include <type_traits>
#include <atomic>
#include <thread>

struct Point
{
	int x;
	int y;
};

//int x = 0; // 전역변수 :  멀티 쓰레드 환경에 안전하지 않다.
std::atomic<int> x = 0; //std::atomic : 멀티 쓰레드에 안전함
void foo()
{
	++x; //atomic : 이순간 mutex 등 OS의 도구가 아닌..
		//CPU의 명령을 사용해서 쓰레드 안전하게 1증가한다.
		//OS의 동기화 도구가 아닌, CPU의 명령으로 해결한다.
		// -> "lock-free" 라고 한다.
	std::cout << x.is_lock_free() << std::endl;
				//true : CPU 명령으로 동기화
				//false : 동기화를 위한 다른 방식 사용
}


int main()
{
	std::thread t1(foo);
//	std::thread t2(foo);
	t1.join();
//	t2.join();
}