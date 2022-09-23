class X {};

// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
// 방법1. call by value
// -> 특징 : 복사본 생성
//void foo(X arg) {}

// 방법2.call by const lvalue reference
// -> 복사본은 생성되지 않지만
// -> const 속성이 추가됨.. (move사용X)
//void foo(const X& arg) {}

// 방법3. 2개의 foo() 함수 - C++11 부터 가능
//-> 복사본도 없고, const 속성도 추가되지 않음
//void foo(X& arg) {} //lvalue일경우
//void foo(X&& arg) {}//rvalue일경우

// 방법4. forwarding reference를 사용하면 "방법3"의 2개 함수를 자동 생성
// -> X 타입 뿐 아니라.. "모든 타입"에 대해 사용가능
template<typename T> void foo(T&& arg) {}

int main()
{
	X x;

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(x);
	foo(X());
}
