#include <iostream>
#include <string>

class People
{
	std::string name;
public:

	void setName(const std::string& s)
	{
		name = s;
	}

	// �ٽ� 1. move�� �����ϴ� setter�� �������
	// 2���� ������ �մϴ�.
	void setName(std::string&& s)
	{
		name = std::move(s);

//		name = s;	//�׳� �̷��� �ϸ� �ȵǳ�?
					//s�� Ÿ���� string&& �̴ϱ�..
					//s�� �̸��� �����Ƿ� "lvalue" �̴�.
					//���ڵ�� move�� �ƴ� ���� ���� �����ڸ� ȣ���Ѵ�.


		//Ÿ�԰� value �Ӽ��� �򰥸��� �ȵȴ�.
//		std::string&& ss = std::string("hello");
		//							Ÿ��			value �Ӽ�
		// std::string("hello")		string			rvalue(�ӽð�ü, �̸�����)
		// ss						string&&		lvalue(�̸�����)
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);				//copy
	p.setName(std::move(s2));	//move

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}