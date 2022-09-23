#include <iostream>
#include <type_traits>
#include <atomic>
#include <thread>

struct Point
{
	int x;
	int y;
};

//int x = 0; // �������� :  ��Ƽ ������ ȯ�濡 �������� �ʴ�.
std::atomic<int> x = 0; //std::atomic : ��Ƽ �����忡 ������
void foo()
{
	++x; //atomic : �̼��� mutex �� OS�� ������ �ƴ�..
		//CPU�� ����� ����ؼ� ������ �����ϰ� 1�����Ѵ�.
		//OS�� ����ȭ ������ �ƴ�, CPU�� ������� �ذ��Ѵ�.
		// -> "lock-free" ��� �Ѵ�.
	std::cout << x.is_lock_free() << std::endl;
				//true : CPU ������� ����ȭ
				//false : ����ȭ�� ���� �ٸ� ��� ���
}


int main()
{
	std::thread t1(foo);
//	std::thread t2(foo);
	t1.join();
//	t2.join();
}