#include <iostream>

int g = 10;

class Point
{
	int x = 0;
	int y = ++g; // ����� �̷� �ʱ�ȭ�� ���� �� ��..
public:
	Point() {} // : x(0). y(++g)
	Point(int a) : x(a) {} // : x(a). y(++g)
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1;
	Point p2(0);
	Point p3(0, 0);

	std::cout << g << std::endl;
	//-> ++g�� �� 2ȸ ����� g�� 12�� ��µȴ�.

	//���..
	//�ɹ� ���� �ʱ�ȭ�� ���ͷ� ������ �ʱ�ȭ�� ����ض�.


	//���..
	//�ɹ����� �ʱ�ȭ�� �ɹ����� ����� �ٷ� �ʱ�ȭ �ض�.(â���� ���̵�)
}