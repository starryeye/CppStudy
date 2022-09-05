#include <iostream>

//--------------------------------
// Temporary(�ӽð�ü) �� Ư¡
// ĳ����
//--------------------------------

//��� Ŭ����
struct Base
{
	int value = 10;
};

//�Ļ� Ŭ����
struct Derived : public Base
{
	int value = 20; //���Ŭ������ �����̸��� �����ϰ� �Ļ�Ŭ�������� ���..
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl; // �Ļ�Ŭ���� 20�� ��µȴ�.

	std::cout << static_cast<Base&>(d).value << std::endl;	// ���Ŭ������ 10�� ��µȴ�.

	std::cout << static_cast<Base>(d).value << std::endl;	// ���Ŭ������ 10�� ��µȴ�.
															// Base Ÿ���� �ӽ� ��ü�� d�� ���� �Ͽ� ����Ե�. 
															// ������ �ӽð�ü�� value�� ����ϰԵȰ�.



	static_cast<Base&>(d).value = 30;	//ok
	static_cast<Base>(d).value = 30;	//error. Base �ӽð�ü�� ������ �ڵ��̴�.

	//���. �ӽð�ü��
	//1. �����ڰ� �ǵ������� ����⵵ �ϰ�( ��κ� �Լ� ���� f1(Point(1,2) )
	//2. "��Ÿ������ ��ȯ�ϴ� �Լ�", "�� Ÿ������ ĳ����" ���� �� �� �����ȴ�.

	//-> �����ı��� �̷�����Ƿ� ���������� ������ �ȴ�. 
	//-> �������� ���� ������ �ɼ��� �ִ�.. -> Counter ��ü�� ����..temporary5 ����.
}