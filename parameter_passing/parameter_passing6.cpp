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

	// 아래 setter를 생각해봅시다.
	// 핵심 : 인자가 2개인 setter 입니다.
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

	// 인자가 2개인 setter를 move 지원하려면 4개의 setter 필요
	// 인자가 3개인 setter를 move 지원하려면 8개의 setter 필요
	// 인자가 2개인 생성자도 move 지원하려면 4개의 생성자 필요
	// ...
	// 이런 복잡한 짓을 해결하는 것이.. forwarding reference이다.

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