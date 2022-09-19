#include <string>

class People1
{
	std::string name;
	int age;
public:
	//맴버 데이터를 "맴버 초기화 리스트"에서 초기화 - good
	//-> 단, 아래 코드는 move 지원안됨..
	People1(const std::string& s, int a) : name(s), age(a) 
	{
	}
};
// People1 p("kim", 2); // 1. name(s) 모양의 생성자 1회 호출로 값을 넣은 것.

//참고..
//int...
//People1, People2에서 age 초기화는 사실 차이 없다.(어셈블리)

class People2
{
	std::string name;
	int age;
public:
	// 맴버 데이터를 "생성자 블럭 안에서 대입" - bad
	//										//컴파일러가 추가한 코드
	People2(const std::string& s, int a)	// : name()
	{
		name = s;	// name.operator=(s) 즉, 대입연산자 호출
		age = a;
	}
};
//People2 p2("kim", 2); // 1. string의 디폴트 생성자 호출 (컴파일러의 추가 코드)
						// 2. name.operator=(s) 호출
						// 즉, 2번의 함수 호출로 name에 값을 넣은 것이다.


int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);
}