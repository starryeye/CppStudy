// forwarding_reference2 - 아주 아주 중요!!

void f1(int&  r) {}
void f2(int&& r) {}

int n1 = 10;
f1(n1); //ok		n1은 lvalue
f1(10); //error		10은 rvalue

//함수 인자로
//int&	: int 타입의 lvalue만 받겠다는 의미 (lvalue reference 라 부름)
//int&&	: int 타입의 rvalue만 받겠다는 의미 (rvalue reference 라 부름)


//아래는 어떤상황이라도.. T 뒤에 &가 한개만 있으므로 &로 귀결
// T& : 임의의 타입의 lvalue만 받겠다는 의미 (lvalue reference 라 부름)
// T&& : 임의의 타입의 lvalue, rvalue를 모두 받을 수 있다. (universal reference 라 부름)
//			"받을 수 있다"는 것은 "해당 함수를 생성" 한다는 것
//				생성된 함수는 "call by value" 가 아닌 "call by reference"

// f4(n1) : T = int&, T&& = int& && => int&		생성된함수 : f4(int&)
// f4(n1) : T = int,  T&& = int&&				생성된함수 : f4(int&&)

// "universal reference" - effective-c++의 저자가 제안한 이름
// 하지만.. C++ 표준위원회에서는 "forwarding reference" 라 결정함

template<typename T> void f3(T& a)
{
}

int main()
{
	int n1 = 10;

	//1. 타입인자를 명시적으로 전달했을 때 생성된 함수의 모양
	//아래에서 생성된 함수는 모두 lvalue타입이므로 rvalue는 보낼수 없다.
	f3<int>(n1);	// T=int		T&=int&		생성된함수 : f3(int& a)
	f3<int&>(n1);	// T=int&		T&=int& &	생성된함수 : f3(int& a)
	f3<int&&>(n1);	// T=int&&		T&=int&& &	생성된함수 : f3(int& a)

	//2. 타입인자를 생략하면 "함수 인자를 보고" 타입을 결정합니다.
	f3(10); // T를 int, int&, int&& 등 어떤 것으로 해도, 10을 받는 함수는 만들수 없다.
			//컴파일 에러
	f3(n1); // T를 int로 결정(선언이 int), 생성된 함수 f3(int&)
}

// 결국 아래 템플릿의 의미를 파악하는 것이 핵심.
//-> 모든 타입의 모든 형태를 다 받을 수 있게.. 됨
template<typename T> void f4(T&& a)
{
}

int main()
{
	int n1 = 10;

	//1. 타입을 전달하는 경우
	f4<int>(10);	//T=int			T&&=int&&		생성된함수:f4(int&& a)
	f4<int&>(n1);	//T=int&		T&&=int& &&		생성된함수:f4(int& a)
	f4<int&&>(10);	//T=int&&		T&&=int&& &&	생성된함수:f4(int&& a)

	//2. 타입을 전달하지 않는 경우(T의 타입을 어떻게 결정되는지가 중요
	f4(n1);	//1. "int n1" 이므로 "T=int" 로 결정하면 "f4(int&&)" 이므로 에러
			//2. n1을 받으려면 "T=int&"로 결정하자. "f4(int&)"
			//C++표준은 2번으로 동작
	f4(10); //T=int, int&& 모두 가능, 그런데 표준은 T=int로 결정
			//생성된 함수는 f4(int&&)
}

