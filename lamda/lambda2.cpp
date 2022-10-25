#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda when a function won't do (to capture local variables, or to write a local function)

//조건자(predicator) : bool을 반환하는 함수
//단한 조건자 : 인자가 한개인 조건자
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	//주어진 구간에서 첫번째로 나오는 "3" 찾기
	auto ret1 = std::find(v.begin(), v.end(), 3);

	//주어진 구간에서 첫번째로 나오는 "3의 배수" 찾기
	// std::find	: 값 검색
	// std::find_if	: 조건 검색, 3번째 인자로 단항 함수 전달
	auto ret2 = std::find_if(v.begin(), v.end(), foo);
	std::cout << *ret2 << std::endl; //6


	int k;
	std::cin >> k;

	// 주어진 구간에서 첫번째로 나오는 k의 배수를 찾고 싶다.
	auto ret3 = std::find_if(v.begin(), v.end(), "단항함수 + 지역변수k");
}

//일급 객체(first class object)
// -> 함수 인자로 전달가능한 객체
// -> C/C++ 에서는 "함수"도 일급객체 이다.(함수를 다른 함수에 인자로 전달가능하다는 것)
//find_if에 foo를 전달

//클로져(Closure)
// -> 문맥에 포함된 지역변수를 캡쳐할 수 있는 "일급객체"
// -> 즉, 함수 인자로 "함수 + 지역변수"를 같이 전달할 수 있는 것을 "Closure" 라고 한다.

// 일반 함수 : 일급 객체 이지만 클로져는 아니다..
// 함수 객체 : 일급 객체 이고 클로져 이다.