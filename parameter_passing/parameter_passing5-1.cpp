#include <iostream>
#include <string>
#include <array>

class People
{
	std::string name;
	int age;
	std::array<int, 20> data;
public:

	// 핵심 1. copy 와 move 가 확실히 차이가 나는 경우 아래처럼 2개만들어라
	void setName(const std::string& s)
	{
		name = s;
	}

	void setName(std::string&& s)
	{
		name = std::move(s);
	}

	// 핵심 2. 복사가 싸다면(cheap) ..
	// 그냥 call by value 만 제공해도 된다.
	void setAge(int a)
	{
		age = a;
	}

	// 핵심 3. 복사가 비싸고, move도 비싸면..
	// -> const& 로만 하면된다. 어차피 move도 비싸다..
	// move 지원 할 필요 없다.
//	void setData(std::array<int, 20> arr) {} // 크기가 크므로 복사본 오버헤드
	void setData(const std::array<int, 20>& arr) { data = arr; }


	// retain 은 copy든 move든 두개를 지칭한다... 뭐가 됐든 마지막엔 하나를 보관하고 잇는것.
	// 핵심 4. retain 하지 않는 in parameter는 move 고려대상 아니다.
	// -> const& 만 사용하면 된다.
	void print_msg(const std::string& msg)
	{
		std::cout << msg << std::endl;
	}
	//std::string s = "AA";
	//p.setName(s)		: s의 자원을 복사해서 p가 보관(retain).. move 고려 대상)
	//p.print_msg(s)	: s의 자원을 읽기만, move 고려 대상 아니다.

	// 아래 코드 처럼 한개만 만드는 경우는 많지 않다.
	// -> 의미는 뺏기만 하겠다는 것.
	void setAddress(std::string&& addr) {}
//	void setAddress(const std::string& addr) {} //대부분 이렇게 쌍으로 제공

	// p.setAddress(s); // error.
	// p.setAddress(std::move(s)); //ok, 이렇게만 사용해라..
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

// 인자 형태에 따른 의도
// 1. call by value 또는 const reference
// -> in parameter 읽기만 하겠다는 의미
void f1(int n) {}
void f2(const std::string& n) {}

// 2. non-const refeerence
// -> in/out parameter
void f3(std::string& n) {}

// 3. rvalue reference
// -> 인자로 받은 자원을 move 하겠다는 의도
// -> 대부분  "const std::string&" 버전과 함께 2개 제공.
void f4(std::string&& n) {}

// 4. 아래코드는 move 하겠다는 의도가 있는데..
// const는 move 될 수 없다.
// -> 따라서, 현재 까지 아래 처럼 만드는 코드는 문법상 문제 없지만,
// -> 사용할 이유가 없다. (1번 처럼 const string&이면 충분하다)
void f5(const std::string&& n) {}