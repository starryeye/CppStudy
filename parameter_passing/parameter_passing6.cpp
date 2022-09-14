#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	People(const std::string& name, const std::string& addr) : name(name), addr(addr)
	{
	}

	// �Ʒ� setter�� �����غ��ô�.
	// �ٽ� : ���ڰ� 2���� setter �Դϴ�.
	void set(const std::string& s1, const std::string& s2) //1
	{
		name = s1;
		addr = s2;
	}

	void set(std::string&& s1, std::string&& s2) //2
	{
		name = std::move(s1);
		addr = std::move(s2);
	}

	void set(const std::string& s1, std::string&& s2) //3
	{
		name = s1;
		addr = std::move(s2);
	}

	void set(std::string&& s1, const std::string& s2) //4
	{
		name = std::move(s1);
		addr = s2;
	}

	// ���ڰ� 2���� setter�� move �����Ϸ��� 4���� setter �ʿ�
	// ���ڰ� 3���� setter�� move �����Ϸ��� 8���� setter �ʿ�
	// ���ڰ� 2���� �����ڵ� move �����Ϸ��� 4���� ������ �ʿ�
	// ...
	// �̷� ������ ���� �ذ��ϴ� ����.. forwarding reference�̴�.

};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p(s1, s2);

	p.set(s1, s2); //1
	p.set(std::move(s1), std::move(s2)); //2
	p.set(s1, std::move(s2)); //3
	p.set(std::move(s1), s2); //4
}