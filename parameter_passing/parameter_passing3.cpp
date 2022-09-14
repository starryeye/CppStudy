#include <iostream>
#include <vector>
#include <algorithm>

struct Rect
{
	int left, top, right, bottom;
};

// 규칙 1. 함수로 부터 값을 꺼낸다면
// -> 반환 값 사용
Rect f() { }

// 규칙 2. 전달된 인자를 수정한다면
// -> 참조 또는 포인터
// -> 요즘은 참조 권장
// -> 그런데, "no object, no argument"등을 사용하고 싶으면 포인터 사용가능
void f1(Rect& r) {}
void f2(Rect* r = nullptr) {}

f1(0); // error, 참조는 반드시 유효한 객체를 전달해야 한다.
f2(nullptr); //ok, 포인터는 0 또는 nullptr 가능.

// 규칙 3. 전달된 인자를 읽기만 한다면(in parameter)
// 복사 동작이 비싸지 않은 것 : call by balue    ex) foo(int n)
// -> int 같은 primitive type,
// -> unique_ptr 같은 스마트 포인터
// -> 반복자(iterator)

// 복사 동작이 비싼 타입 : call by const reference
// -> 대부분의 user define type


// 인자로 반복자를 받으려고 한다.
// 1,2,3 의 인자는 모두 in parameter
template<typename IT, typename T>
IT find(IT first, IT last, const T& value) //파라미터 타입을 보자..
{
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::find(v.begin(), v.end(), 3);
}
