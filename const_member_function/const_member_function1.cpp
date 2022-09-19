// Con.1 : By default, make objects immutable
// -> �⺻������, ��ü�� immutable�� ������
// Con.2 : By default, make member functions const
// -> �⺻������, �ɹ��Լ��� ����� ������
// Con.3 : By default, pass pointersand references to consts
// -> �⺻������ ??

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() 
	{
		std::cout << x << ", " << y << std::endl;
	}
	//��� ��� �Լ�
	// -> ��� �Լ� () ���ʿ� const�� ���̴� ����
	// -> ���������� ��� �����͸� �������� �ʰڴٰ� �����Ϸ����� �˷��ִ°�
	// �ٽ� : ��� ��ü�� "��� ��� �Լ��� ȣ�� ����"
	void print2() const
	{
//		x = 10; //error
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2); //��� ��ü

	//�ٽ� : pt�� ��� ��ü �Դϴ�.
	pt.x = 10;		//error. x�� public ������, ��� �̹Ƿ�
					
	pt.set(10, 20);	//error. set ���ο��� ���� ��
	pt.print();		//error.
	pt.print2();	//ok, print2() �� const member function �̸�
					//ȣ�� ����

	//����
	//�����Ϸ��� ���� ���� ȣ�� �� �� �ִ��� �������� �ȴ�.
	//-> ��� ���ϸ� include ���ָ� �Լ� ȣ���� ������ ������ ���⿡ �ִ�..
}


