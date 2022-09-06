#include <iostream>

// Rule Of 3/5

// Rule Of 3 : 클래스 안에 포인터가 있고, 동적할당하는 코드가 있다면
//				3개의 special member function 을 만들어야 한다.
//				(소멸자, 복사 생성자, 대입 연산자)
//				C++98 시절의 규칙

// Rule Of 5 : C++11 부터는 위 규칙외에 2개를 더 제공해야한다.
//				(move 생성자, move 대입 연산자)
class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s)+1, s);
	}

	~People() { delete[] name; }

	//복사 생성자
	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}

	//대입 연산자
	//복사 생성자를 만드는 경우 "항상 대입연산자"도 만들어야 한다.
	People& operator=(const People& p)
	{
		if (&p == this) return *this; //자신과의 비교 조사

		delete[] name;

		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
	}

	//move 생성자 (이동 생성자)
	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	//move 대입 연산자 (이동 대입 연산자)
	People& operator=(People&& p)
	{
		if (&p == this) return *this; //자신과의 비교 조사

		delete[] name;

		age = p.age;
		name = p.name;
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



