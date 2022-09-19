#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	//��� �ɹ� �Լ��� Ư¡
	void print() const
	{
		x = 10;			// error 1. ��� ����Լ��� ��������� ������ �ȵȴ�.
		set(10, 20);	// error 2. ��� ����Լ��� ��� ����Լ��� ȣ�� �����ϴ�.
		int* p = reinterpret_cast<int*>(this); // error
		const int* ptr = reinterpret_cast<const int*>(this); // ok
						// print()�϶�, this�� �ڷ����� Point* �Դϴ�.
						// print() const�϶�, this�� const Point �Դϴ�.
						// ��, ��� ��� �Լ������� this�� Ÿ���� �ٸ���.

		std::cout << x << ", " << y << std::endl;
	}

	//4. �����̸��� ���/���� ��� �Լ��� ���ÿ� ���������ϴ�.
	void print()
	{
		std::cout << "non const print" << std::endl;
	}
};

int main()
{
	Point p(1, 2);	//���� ��ü�� "��� ����Լ��� ���� ����Լ� ��� ȣ�� ����
	p.print();		// 1. "print()" ȣ��.. ���ٸ�?
					// 2. "print() const" ȣ��..

	const Point cp(1, 2); // ��� ��ü�� ��� ��� �Լ��� ȣ�Ⱑ��
	cp.print();		// "print() const" �� ȣ�Ⱑ��
}