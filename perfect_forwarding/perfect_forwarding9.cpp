#include <iostream>
#include <string>
#include <vector>
class People
{
	std::string name;
public:
	// move 지원 setter 만들기 #1 (첫날..)
//	void setName(const std::string& s) { name = s; }			
//	void setName(std::string&& s) { name = std::move(s); }		

	// move 지원 setter 만들기 #2
	//T&& 를 사용하면, string&, string&& 버전의 2개 함수를 자동 생성 할 수 있다.
	template<typename T>
	void setName(T&& s)
	{
		//다음중 맞는 것은?
//		name = s;					//1. s는 lvalue 이므로 항상 복사 (대입)
//		name = std::move(s);		//2. std::move 는 rvalue로 캐스팅, 항상 move
		name = std::forward<T>(s);	//3. setName() 호출 시 인자로..
									//lvalue를 보냈으면 복사
									//rvalue를 보냈으면 move
	}
};

int main()
{
	std::string s = "john";

	People p;
	p.setName(s);				
	p.setName(std::move(s));	

	const std::string cs = "kim";
	
					//T&& 사용하면...
	p.setName(s);	//setName(std::string&) 가 생성.
	p.setName(cs);	//setName(const std::string&) 도 생성됨.
					//-> const 버전도 생성되는 것이다!!
					//-> move 지원 setter 만들기 #1 이 더 좋은 경우가 있다.
}



