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

	// 핵심 1. move를 지원하는 setter를 만들려면
	// 2개를 만들어야 합니다.
	void setName(std::string&& s)
	{
		name = std::move(s);

//		name = s;	//그냥 이렇게 하면 안되나?
					//s의 타입이 string&& 이니까..
					//s는 이름이 있으므로 "lvalue" 이다.
					//이코드는 move가 아닌 복사 대입 연산자를 호출한다.


		//타입과 value 속성을 헷갈리면 안된다.
//		std::string&& ss = std::string("hello");
		//							타입			value 속성
		// std::string("hello")		string			rvalue(임시객체, 이름없음)
		// ss						string&&		lvalue(이름있음)
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