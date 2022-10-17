#include <iostream>
#include <string>
#include <vector>
class People
{
	std::string name;
public:
	// move ���� setter ����� #1 (ù��..)
//	void setName(const std::string& s) { name = s; }			
//	void setName(std::string&& s) { name = std::move(s); }		

	// move ���� setter ����� #2
	//T&& �� ����ϸ�, string&, string&& ������ 2�� �Լ��� �ڵ� ���� �� �� �ִ�.
	template<typename T>
	void setName(T&& s)
	{
		//������ �´� ����?
//		name = s;					//1. s�� lvalue �̹Ƿ� �׻� ���� (����)
//		name = std::move(s);		//2. std::move �� rvalue�� ĳ����, �׻� move
		name = std::forward<T>(s);	//3. setName() ȣ�� �� ���ڷ�..
									//lvalue�� �������� ����
									//rvalue�� �������� move
	}
};

int main()
{
	std::string s = "john";

	People p;
	p.setName(s);				
	p.setName(std::move(s));	

	const std::string cs = "kim";
	
					//T&& ����ϸ�...
	p.setName(s);	//setName(std::string&) �� ����.
	p.setName(cs);	//setName(const std::string&) �� ������.
					//-> const ������ �����Ǵ� ���̴�!!
					//-> move ���� setter ����� #1 �� �� ���� ��찡 �ִ�.
}



