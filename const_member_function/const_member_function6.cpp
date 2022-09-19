#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� ��� �Լ�
	// -> C#, Java ���� ���� �θ� ���Ǵ� ��� �Լ�.
	// -> ��� ��ü(const Point p(1, 2)) �� toString() ȣ�� �����ؾ� �Ѵ�.
	// -> ����, ��� ����Լ��� �ؾ��Ѵ�. const
	const char* toString() const
	{
		static char s[32];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};
int main()
{
	Point pt(1, 2);
	std::cout << pt.toString() << std::endl;
	std::cout << pt.toString() << std::endl;
}

