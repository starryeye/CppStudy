// E.25: If you can't throw exceptions, simulate RAII for resource management
// CP.20: Use RAII, never plain lock() / unlock()
// F.9: Unused parameters should be unnamed

#include <iostream>
#include <mutex>

//함수 오버로딩에 사용한 "꼬리표(tag)" 타입을 설계 하자..
// 대부분 empty class를 사용한다.
struct adopt_lock_t {};
adopt_lock_t adopt_lock;

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
//	lock_guard(T& m, int n) : mtx(m) {} //int가 맘에 안듬
	lock_guard(T& m, adopt_lock_t) : mtx(m) {} //사용되지 않는 파라미터는 이름을 주지말자.. (adopt_lock "n"에서 n삭제)
	~lock_guard() { mtx.unlock(); }
};


std::mutex m;

int shared_data = 0; 

void foo()
{
	//C++ 표준에는 mutex를 lock 하는 방법이 여러가지 있다.
	if (m.try_lock())
	{
		//lock은 직접 했지만(다양한 이유로..)
		//unlock 은 안전하게 RAII로 하고싶다..
		
		//lock_guard<std::mutex> g(m, adopt_lock); //adopt_lock은 17line으로 갈지.. 19line에 갈지 선택하는 꼬리표이다.
		std::lock_guard<std::mutex> g(m, std::adopt_lock); //C++ 표준
	}
}


int main()
{

}