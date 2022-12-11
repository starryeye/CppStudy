// E.25: If you can't throw exceptions, simulate RAII for resource management
// CP.20: Use RAII, never plain lock() / unlock()
// F.9: Unused parameters should be unnamed

#include <iostream>
#include <mutex>

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
	//참고..
	//C++에서 소멸자는 절대 예외를 발생시키면안된다.
	//noexcept 를 표기하지 않아도 모든 소멸자는 noexcept이다.
};


std::mutex m; //C++ 표준 동기화 클래스

int shared_data = 0; //전역변수는 모든 스레드가 공유
					//thread-safe하지 않음..

//아래 함수를 2개이상의 스레드가 실행.
void foo()
{
	std::lock_guard<std::mutex> g(m); // C++ 표준
	//lock_guard<std::mutex> g(m); //RAII 를 사용하는 기술
								//핵심 : 예외가 발생해도 지역변수는 안전하게 파괴된다.
								//			소멸자가 호출됨을 보장
								//			-> stack unwingind (스택 풀기)
//	m.lock();//직접 lock, unlock 하지말자..
	shared_data = 100;

	// 예외 발생.. 하면.. unlock 못함.. -> 데드락
	// try-catch.. ? 예외를 다 .. 볼수가 없을 경우...
//	m.unlock();
}
//만약에..
//foo 내부 일부에서 lock unlock이 필요할 경우..
//lock_guard를 중괄호로 묶자

int main()
{

}