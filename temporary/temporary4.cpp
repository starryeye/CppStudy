#include <iostream>

//--------------------------------
// Temporary(�ӽð�ü) �� Ư¡
// �Լ� ����
// �Լ� ��ȯ
//--------------------------------

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

/*
//�Լ� ��ȯ���� �ӽð�ü!
void f1(Point  pt) {} //call by value, ���纻 ������
void f2(Point& pt) {} //call by reference. ���纻 ����

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/

//-----------------------------------
Point pt(1, 2); //�������� pt

Point f1()		//return by value, �ӽð�ü(Point)�� �����Ǿ� ��ȯ��.
{
	return pt;	//���Ͽ� ���纻�� ���������.
}

Point& f2()		//return by reference, pt��ü�� ��ȯ�Ѵ�.
{
	return pt;
}

Point& f3()
{
	Point p(1, 2);
	return p;	//�����̴�. ���������� ������ ��ȯ�ϸ� �ȵȴ�.
				//�������� ������ ����ȯ�� ����ؾ��Ѵ�.
}//<- �������� p �ı�. �ı��Ǵ� ���� �����ϸ� �ȵ�.

//���� ��ȯ�� "��������, �ɹ� ������, *this, static ����" �� ����.
// -> �ı����� �ʴ� �͸� ����ؾ� �Ѵ�.
// F.43: Never (directly or indirectly) return a pointer or a reference to a local object


int main()
{
	f1().x = 10;	//error. ���Ͽ� �ӽð�ü.x = 10
					//�ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����.
					//���Ͽ� �ӽð�ü�� �Լ� ȣ�� ������ ������ �ı��Ǳ� ����

	f2().x = 10;	//ok. pt.x = 10�� ����
}