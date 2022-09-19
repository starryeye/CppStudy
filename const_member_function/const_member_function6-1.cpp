#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	//mutable : ��� ��� �Լ� �ȿ����� ���� ������ �� �ִ� �ɹ� ������ ���鶧 ���
	mutable char cache[32];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	//x,y�� ������ ������.. ���� ������ �ٸ� ���� ������ const�� ���� ���⿡ ó��..
	// -> mutable..
	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
	//x, y �� �����ϴ� ��� �Լ����� "cache_valid = false �� ����
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}