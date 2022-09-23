#include <iostream>
#include <type_traits>
#include <atomic>
#include <thread>
//std::atomic<사용자정의타입> 의 조건
//1. 반드시 복사, move 관련 특수 함수가 trivial 해야 한다.
//2. sizeof(타입) <  64bit 라면 64bit 환경에서 lock-free로 동작
//	 sizeof(타입) >	 64bit 인경우는 lock-free 아님.(spin lock 사용)

//atomic<T> requires T to be trivially copyable, copy constructible, 
//								move constructible, 
//									copy assignable, and move assignable.
struct Point
{
	int x; //32bit 데이터
	int y; //32bit 데이터
	//------총 64bit 데이터-----

//	int z; //32bit 데이터, z가 추가되면 64bit가 초과되어 64bit CPU에서 락프리하지 않음

	Point(const Point& pt) : x(pt.x), y(pt.y) {} //atomic<사용자정의타입> 조건에 위배..
};

std::atomic<Point> pt;

void foo()
{
	Point p = pt.load(); // thread-safe하게 복사

	std::cout << pt.is_lock_free() << std::endl;
}


int main()
{
	foo();
}