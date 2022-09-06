#include <iostream>
#include <string>

// Rule Of 0

// �ٽ� : �ڿ��� ���� �������� ����, �ڿ� ���� Ŭ������ �������..
// ���ڿ��� �ʿ��ϸ� : char* -> std::string
// ���� ���� : int* -> std::vector<int> �Ǵ� ����Ʈ ������

// �⺻ ���۰� ������ �۾��� �ϴ� special member function�� ����������..
// -> �����Ϸ��� ���鵵�� ����..

// copy�� move�� ��������ϴ� Ŭ����
class People
{
	std::string name;
	int   age;
	std::string address;
public:
	People(const std::string& s, int a, const std::string& addr = "unknown")
		: name(s), age(a), address(addr)
	{
	}

	//�Ʒ��� ���� �����Ϸ��� �ϴ� �Ͱ� ������ ���� �����ڸ� ����������..
	//move �����ȵ�.. (�ݴ뵵 ��������)
//	People(const People& p) :name(p.name), age(p.age), address(p.address)
};
int main()
{
	People p1("kim", 20);
	People p2 = p1;			//���� ������ (����鼭 �ֱ�)
	p2 = p1;				//���� ������ (�����Ŀ� �ֱ�)
	//=======C++98=========


	//=======C++11=========
	People p3 = std::move(p1);
	p3 = std::move(p2);
}



