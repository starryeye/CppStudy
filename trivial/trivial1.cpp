// SL.con.4: don’t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

#include <iostream>

// trivial : "특수 맴버함수"가 하는 일이 "자명(널리 알려진 디폴트 방식대로 동작)" 하다는 의미.
// trivial 생성자		: 아무 일도 하지 않은 생성자
// trivial 복사 생성자	: 모든 멤버를 얕은 복사하는 복사 생성자.
// trivial 소멸자		: 아무일도 하지 않는 소멸자


class A
{
};

// B의 생성자는 trivial 할까요 ?
class B 
{
	int data;
public:
	virtual void foo() {}	//생성자를 안만들었지만..
							//가상함수가 있다면..
							//컴파일러가 가상함수 테이블을 만들어 매핑하는 작업을함..
							//따라서.. 이 생성자는 trivial 하지 않다..
};

//생성자가 trivial 한 조건..
//1. 가상함수가 없고..
//2. 객체형 맴버데이터가 없거나, 객체형 맴버데이터의 생성자가 trivial하고
//3. 기반클래스가		없거나, 기반 클래스의		생성자가 trivial하고
//4. 사용자가 만든 생성자가 없을 때.

//생성자는 "trivial"하다 -> 하는일이 없다.


int main()
{
	// malloc으로 객체를 만들면 생성자 호출이 안된다.
	B* p = (B*)malloc(sizeof(B));

	p->foo(); //생성자가 호출되지 않은 객체의 가상함수 호출

	new(p) B; // 이미 할당된 메모리에 생성자만 호출 - 내일 배움..
	
	p->foo(); //생성자 호출 후 가상함수 호출.
}

// 종료코드(0) 가 나와야 제대로 실행 된 것이다.