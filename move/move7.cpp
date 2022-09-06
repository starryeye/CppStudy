#include <iostream>
#include <string>
#include <vector>
#include <array>

void foo()
{
	//핵심 1 . STL의 대부분의 클래스는 move 생성자를 제공한다.
	std::string s1 = "asdlkajsdlfkasdfa";
	std::string s2 = s1; //자원(문자열)의 복사, 깊은복사

	std::string s3 = "asdlkajsdlfkasdfa";
	std::string s4 = std::move(s3); //자원(문자열)의 이동, 얕은복사후 파괴

	std::cout << s1 << std::endl; //출력 : "asdlkajsdlfkasdfa"
	std::cout << s3 << std::endl; //출력 : ""


	//핵심2. primitive type 이나 자원을 동적하지 않은 타입은
	//대부분 move의 효과가 없다.(std::move 사용해도 되긴함. )
	int n1 = 100;
	int n2 = std::move(n1); //static_cast<int&&>(n1) 이다.
							//int n2 = n1 과 완전히 동일하다.
							//효과가 없다 단순한 캐스팅일 뿐이다.
							//n1이 0으로 초기화되지 않음

	int* p1 = &n1;
	int* p2 = std::move(p1); //역시 캐스팅에 불과하다.. 효과가 없다
							 //p1이 nullptr로 바뀌지 않음

	std::array<int, 5> arr1 = { 1,2,3,4,5 };
	std::array<int, 5> arr2 = std::move(arr1);

	std::cout << arr1.size() << std::endl;  //array는 자원을 계속 소유한다. (복사함)
											//array는 동적할당하지 않기때문이다..(스택에 관리)
											//그냥 캐스팅에 불과하다.

	//std::move()는 현재(C++23)까지는 단순한 캐스팅이다.
	//-> 미래에는 변경될 수 도 있다..
}
//참고
//STL 컨테이너중 자원을 동적할당하지 않은 컨테이너(move 해도 효과는 거의 없다.)
//std::array
//std::pair, std::tuple
//std::variant(C++17)
// move할지말지는 동적할당을 하냐마냐에 갈린다.



//핵심 3. 알고리즘 만들때 복사를 사용할지 move를 사용할지 잘 판단할것.
//적절한 std::move() 사용은 성능을 향상 시킨다.
//참고로.. primitive type 은 Swap, Swap2 의미 없다.

template<typename T>
void Swap(T& a, T& b)
{
	//아래 코드는 복사에 의한 swap이다.. 느리다..
	//깊은 복사 3회 일어난다..
	T tmp = a; //깊은복사..
	a = b; //깊은복사..
	b = tmp; //깊은복사..
}

template<typename T>
void Swap2(T& a, T& b)
{
	//아래 코드는 move에 의한 swap이다.. 빠르다
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	foo();

	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
	Swap2(s1, s2);
}



