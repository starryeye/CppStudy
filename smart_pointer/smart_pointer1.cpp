// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

void foo()
{
	int* p1 = new int;

	std::shared_ptr<int> sp(new int);

	if (실패)
	{
		//p1을 직접 delete하고 돌아가야 합니다.
		//sp 는 소멸자가 delete 해주므로 안전합니다.
		return;
	}

	// 어떤 작업을 하다가 예외 발생
	throw 1;	//p1이 가리키는 메모리는 누수
				//sp는 예외가 나와도 지역변수 이므로 안전하게 파괴
				// -> sp가 가진 자원은 delete 됨.
	//......

	delete p1; //자원해지를 직접 하는 경우
} //<- 스마트 포인터 sp의 소멸자 호출, 소멸자가 자원 해지

int main()
{
	try
	{
		foo();
	}
	catch(...) {}
	
}