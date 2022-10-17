#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 아래 생성자는 move 지원이 안된다.
	// -> T&& 로 만들어야 한다. 클래스 아래 부분 참고
//	People(const std::string& name, const std::string& addr) : name(name), addr(addr)
//	{
//	}

	//인자가 2개인 setter
	//-> 아래처럼만 만들면 move 지원 안된다.
	//-> 인자가 2개인 setter가 move를 지원하려면 4개의 함수를 제공해야 한다.
//	void set(const std::string& n, const std::string& a)
//	{
//		name = n;
//		addr = a;
//	}

	//인자가 2개 이상인 setter가 move를 지원하려면
	//	T&&를 사용하는 것이 좋다.
	//보통.. 인자가 1개인경우는 직접 2개의 함수를 직접하는 편이고..
	//인자가 2개이상이면 T&& 사용하자..
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}

	//move 지원하는 생성자..
	template<typename T1, typename T2>
	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), addr(std::forward<T2>(a))
	{
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2); 
	People p2(std::move(s1), s2); 
	People p3(s1, std::move(s2)); 
								  
	People p4(std::move(s1), std::move(s2));

}
//핵심 1. move를 지원하는 setter/생성자 만들기.
// 인자가 1개라면.. : 2개(const&, && 버전)의 setter 만들자 (9번.cpp 참고)
// 인자가 2개 이상이라면.. : T&& 를 사용하자.. (위코드 참고)

//핵심 2. T&& 의 주된 용도
// 완벽한 전달 기술 : 전달받은 인자를 다른 함수로 보낼때 (chronometry 예제)
// move 지원 setter 또는 생성자 만들때 (위 예제)

