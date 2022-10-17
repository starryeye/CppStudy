#include <iostream>

void hoo(int&& arg) {}

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10);
	chronometry(hoo, 10);

	int&& arg = 10; //10은 rvalue 입니다.
					//arg는 이름이 있다..그리고 lvalue이다..
	//타입과 value 속성을 잘 구별 해야한다.
	//			타입		value 속성
	//10		int			rvalue
	//arg		int&&		lvalue..(등호의 왼쪽.. 그리고 이름있으니까..)

	hoo(10); //hoo(rvalue) 이므로 ok
	hoo(arg);//hoo(lvalue) 이므로 error

	hoo(static_cast<int&&>(arg)); //ok
					// -> arg가 int&& 타입인데, 결국 같은 타입 캐스팅 아닌가..?
					// -> 위 표기법은 "타입 캐스팅"이 아닌,
					// -> value 속성을 변경하는.. 캐스팅이다.
					// -> C++표준 문서에 명시되어있음.
					// lvalue를 rvalue로 변경하는 value 속성 캐스팅이다.
}
