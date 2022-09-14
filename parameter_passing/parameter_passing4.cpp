#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// �Ʒ� setter�� C++98 �������� "�ּ��� �ڵ�"�̴�.
	// �׷���.. C++11 ���ʹ� ���� �����ϴ�.
	// -> move�� ������ �� ���� setter �̴�.
	void setName(const std::string& s)
	{
		//name = s; //�׻� ���� ���� ������ ȣ��
		name = std::move(s);	//�׻� ���� ���Կ����� ȣ��
								//������ "�����ü�� move �ɼ� �����Ƿ�"
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName(std::move(s2)); //�ǵ����� ����.. ���簡 �Ǿ����

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}