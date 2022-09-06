#include <iostream>
#include <string>

//C. 61: A copy operation should copy
//C. 64 : A copy operation should move and leave ists source in a valid state
//복사 생성자에서는 복사를
//move 생성자에서는 move를 하라.

class People
{
	char* name;
	int   age;
	std::string address; //string 타입의 맴버변수가 추가되었다.
public:
	People(const char* s, int a, const std::string& addr = "unknown") 
		: age(a), address(addr)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s) + 1, s);
	}

	~People() { delete[] name; }

	//복사 생성자
	People(const People& p) : age(p.age), address(p.address)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	//대입 연산자
	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		address = p.address;

		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
	}

	//move 생성자 (이동 생성자)
	People(People&& p) 
//		: name(p.name), age(p.age), address(p.address) // <- 잘못된 코드이다.
		//string의 복사 생성자가 호출 된것이다.
		: name(p.name), age(p.age), address(std::move(p.address)) // ok
		// -> move 생성자는 모든 맴버를 move로 옮겨야한다.
		// -> 단, primitive type은 std::move를 사용해도 되고 안해도 됨(의미 없음)
	{
		p.name = nullptr;
	}

	//move 대입 연산자 (이동 대입 연산자)
	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		delete[] name;

		age = p.age;
		name = p.name;
//		address = p.address;			//복사 대입 연산자를 사용했다.. move 대입 연산자를 사용해야한다.
		address = std::move(p.address); //ok

		p.name = nullptr;

		return *this;
	}
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



