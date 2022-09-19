#include <string>

class People1
{
	std::string name;
	int age;
public:
	//�ɹ� �����͸� "�ɹ� �ʱ�ȭ ����Ʈ"���� �ʱ�ȭ - good
	//-> ��, �Ʒ� �ڵ�� move �����ȵ�..
	People1(const std::string& s, int a) : name(s), age(a) 
	{
	}
};
// People1 p("kim", 2); // 1. name(s) ����� ������ 1ȸ ȣ��� ���� ���� ��.

//����..
//int...
//People1, People2���� age �ʱ�ȭ�� ��� ���� ����.(�����)

class People2
{
	std::string name;
	int age;
public:
	// �ɹ� �����͸� "������ �� �ȿ��� ����" - bad
	//										//�����Ϸ��� �߰��� �ڵ�
	People2(const std::string& s, int a)	// : name()
	{
		name = s;	// name.operator=(s) ��, ���Կ����� ȣ��
		age = a;
	}
};
//People2 p2("kim", 2); // 1. string�� ����Ʈ ������ ȣ�� (�����Ϸ��� �߰� �ڵ�)
						// 2. name.operator=(s) ȣ��
						// ��, 2���� �Լ� ȣ��� name�� ���� ���� ���̴�.


int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);
}