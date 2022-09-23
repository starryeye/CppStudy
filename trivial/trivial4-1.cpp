#include <iostream>
#include <type_traits>
#include <atomic>
#include <thread>
//std::atomic<���������Ÿ��> �� ����
//1. �ݵ�� ����, move ���� Ư�� �Լ��� trivial �ؾ� �Ѵ�.
//2. sizeof(Ÿ��) <  64bit ��� 64bit ȯ�濡�� lock-free�� ����
//	 sizeof(Ÿ��) >	 64bit �ΰ��� lock-free �ƴ�.(spin lock ���)

//atomic<T> requires T to be trivially copyable, copy constructible, 
//								move constructible, 
//									copy assignable, and move assignable.
struct Point
{
	int x; //32bit ������
	int y; //32bit ������
	//------�� 64bit ������-----

//	int z; //32bit ������, z�� �߰��Ǹ� 64bit�� �ʰ��Ǿ� 64bit CPU���� ���������� ����

	Point(const Point& pt) : x(pt.x), y(pt.y) {} //atomic<���������Ÿ��> ���ǿ� ����..
};

std::atomic<Point> pt;

void foo()
{
	Point p = pt.load(); // thread-safe�ϰ� ����

	std::cout << pt.is_lock_free() << std::endl;
}


int main()
{
	foo();
}