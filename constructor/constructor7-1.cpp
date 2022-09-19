#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {} // ����ڰ� ���� ���� ������!
	Point() = default; // �����Ϸ��� ���� ������.
};

int main()
{
	int n1;		//�����Ⱚ
	int n2 = 0; //C++98 ��Ÿ��
	int n3{ 0 };//C++11 ���� ����, value initialization�̶� �θ�
	int n4{};	//C++11 ���� ����, default initialization�̶� �θ�
				//-> 0���� �ʱ�ȭ ��.
				//"����ڰ� ���� ���� ������!"�� �ִٸ�.. �����Ⱚ �ʱ�ȭ..

	Point pt{}; //��� �ɹ��� "����Ʈ��(0)"���� �ʱ�ȭ
				// -> ����ڰ� �������� ������ ���� ��.
				// -> �����Ϸ��� ���� �����ڶ�� ����.
	std::cout << pt.x << " " << pt.y << std::endl; //0
}
// www.godbolt.org �� �����غ���..
// -> �پ��� ����� "������ڵ�"�� Ȯ�� �� �� �ִ� ����Ʈ.


//-> godbolt����.. �Ʒ� �ڵ� ..
/*
struct Point
{
	int x = 0;
	int y;

	//	Point() {} // ����ڰ� ���� ���� ������!
	Point() = default; // �����Ϸ��� ���� ������.
};

int main()
{
	Point pt;
}
// www.godbolt.org �� �����غ���..
// -> �پ��� ����� "������ڵ�"�� Ȯ�� �� �� �ִ� ����Ʈ.
*/