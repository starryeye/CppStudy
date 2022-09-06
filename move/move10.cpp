#include <iostream>
#include <string>

// Rule Of 0

// 핵심 : 자원을 직접 관리하지 말고, 자원 관리 클래스를 사용하자..
// 문자열이 필요하면 : char* -> std::string
// 동적 버퍼 : int* -> std::vector<int> 또는 스마트 포인터

// 기본 동작과 동일한 작업을 하는 special member function을 만들지마라..
// -> 컴파일러가 만들도록 하자..

// copy와 move를 모두지원하는 클래스
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

	//아래와 같이 컴파일러가 하는 것과 동일한 복사 생성자를 만들지마라..
	//move 지원안됨.. (반대도 마찬가지)
//	People(const People& p) :name(p.name), age(p.age), address(p.address)
};
int main()
{
	People p1("kim", 20);
	People p2 = p1;			//복사 생성자 (만들면서 넣기)
	p2 = p1;				//대입 연산자 (만든후에 넣기)
	//=======C++98=========


	//=======C++11=========
	People p3 = std::move(p1);
	p3 = std::move(p2);
}



