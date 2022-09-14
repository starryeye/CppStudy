#include <iostream>
#include <string>
#include <array>

class People
{
	std::string name;
	int age;
	std::array<int, 20> data;
public:

	// �ٽ� 1. copy �� move �� Ȯ���� ���̰� ���� ��� �Ʒ�ó�� 2��������
	void setName(const std::string& s)
	{
		name = s;
	}

	void setName(std::string&& s)
	{
		name = std::move(s);
	}

	// �ٽ� 2. ���簡 �δٸ�(cheap) ..
	// �׳� call by value �� �����ص� �ȴ�.
	void setAge(int a)
	{
		age = a;
	}

	// �ٽ� 3. ���簡 ��ΰ�, move�� ��θ�..
	// -> const& �θ� �ϸ�ȴ�. ������ move�� ��δ�..
	// move ���� �� �ʿ� ����.
//	void setData(std::array<int, 20> arr) {} // ũ�Ⱑ ũ�Ƿ� ���纻 �������
	void setData(const std::array<int, 20>& arr) { data = arr; }


	// retain �� copy�� move�� �ΰ��� ��Ī�Ѵ�... ���� �Ƶ� �������� �ϳ��� �����ϰ� �մ°�.
	// �ٽ� 4. retain ���� �ʴ� in parameter�� move ������ �ƴϴ�.
	// -> const& �� ����ϸ� �ȴ�.
	void print_msg(const std::string& msg)
	{
		std::cout << msg << std::endl;
	}
	//std::string s = "AA";
	//p.setName(s)		: s�� �ڿ��� �����ؼ� p�� ����(retain).. move ��� ���)
	//p.print_msg(s)	: s�� �ڿ��� �б⸸, move ��� ��� �ƴϴ�.

	// �Ʒ� �ڵ� ó�� �Ѱ��� ����� ���� ���� �ʴ�.
	// -> �ǹ̴� ���⸸ �ϰڴٴ� ��.
	void setAddress(std::string&& addr) {}
//	void setAddress(const std::string& addr) {} //��κ� �̷��� ������ ����

	// p.setAddress(s); // error.
	// p.setAddress(std::move(s)); //ok, �̷��Ը� ����ض�..
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);				
	p.setName(std::move(s2));	

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}

// ���� ���¿� ���� �ǵ�
// 1. call by value �Ǵ� const reference
// -> in parameter �б⸸ �ϰڴٴ� �ǹ�
void f1(int n) {}
void f2(const std::string& n) {}

// 2. non-const refeerence
// -> in/out parameter
void f3(std::string& n) {}

// 3. rvalue reference
// -> ���ڷ� ���� �ڿ��� move �ϰڴٴ� �ǵ�
// -> ��κ�  "const std::string&" ������ �Բ� 2�� ����.
void f4(std::string&& n) {}

// 4. �Ʒ��ڵ�� move �ϰڴٴ� �ǵ��� �ִµ�..
// const�� move �� �� ����.
// -> ����, ���� ���� �Ʒ� ó�� ����� �ڵ�� ������ ���� ������,
// -> ����� ������ ����. (1�� ó�� const string&�̸� ����ϴ�)
void f5(const std::string&& n) {}