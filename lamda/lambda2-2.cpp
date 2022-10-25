#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)


int main()
{
//	int add(int a, int b) {} //error 함수 안에 함수 안된다.
								//그러나 함수 안에 클래스(함수객체) 된다.
								//지역변수 캡쳐 능력을 가지려면 함수안에 함수를 만들 수 있어야 한다.

	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };


	int k = 3;


	auto ret = std::find_if(v.begin(), v.end(), [k](int n) {return n % k == 0; });

	//람다 표현식의 원리.
	//위 코드를 보고 컴파일러가 아래 코드를 생성한다..
	class CompilerGeneratedName
	{
		int k; //람다 표현식이 캡쳐한 변수 값을 보관할 맴버 데이터
	public:
		CompilerGeneratedName(int n) : k(n) {}

		bool operator()(int n) const
		{
			return n % k == 0;
		}
	};
	//그리고, 람다표현식이 있던 위치에 컴파일러가 만든 클래스의 임시객체를 생성하는 코드로 변경
	auto ret2 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k));
}
