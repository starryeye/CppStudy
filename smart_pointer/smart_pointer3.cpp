// R.11: Avoid calling new and delete explicitly
// R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
// E.6: Use RAII to prevent leaks

#include <iostream>
#include <memory>

int main()
{
	int* p = new int;

	std::shared_ptr<int> sp1(p);// 포인터 관리는 sp1이 함.
								//관리객체 만들고 혼자 쓰므로 1

	std::shared_ptr<int> sp2 = sp1; //안전함.
									//sp1이 사용하는 동일한 관리객체에 2로 업데이트

	//그런데 아래 코드를 생각해보자.
	std::shared_ptr<int> sp3(p); //sp3는 sp1, sp2의 존재를 모른다.
								//관리객체 1로 함!
								//-> sp3는 sp1, sp2와 다른 관리객체를 사용한다.
								//-> 이렇게 사용하면 안된다.

	//핵심. 스마트 포인터로 자원을 관리할때는
	// 근원적으로 raw pointer 자체에 담지말자.. 버그의 원인이다.
	int* p2 = new int; //이렇게 하지말라는 것.

	std::shared_ptr<int> sp4(new int); //위 보다는 좋다..(raw pointer 등장안함)

	std::shared_ptr<int> sp5 = std::make_shared<int>(0); //best

	//자원관리 객체가 초기화될때 자원도 할당해라..
	//RAII
}
