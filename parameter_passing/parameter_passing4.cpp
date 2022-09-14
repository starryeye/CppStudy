#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// 아래 setter는 C++98 시절에는 "최선의 코드"이다.
	// 그러나.. C++11 부터는 많이 부족하다.
	// -> move를 지원할 수 없는 setter 이다.
	void setName(const std::string& s)
	{
		//name = s; //항상 복사 대입 연산자 호출
		name = std::move(s);	//항상 복사 대입연산자 호출
								//이유는 "상수객체는 move 될수 없으므로"
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);
	p.setName(std::move(s2)); //의도하지 않은.. 복사가 되어버림

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}