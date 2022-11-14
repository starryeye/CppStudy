// T44. Use function templates 
// to deduce class template argument types

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// C++17 이전에는 클래스 템플릿의 인자 추론을 위해
// 함수 템플릿을 사용한다..
template<typename T>
List<T> make_list(int sz, T value)
{
	return List<T>(sz, value);
}

int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3); //타입을 전달 - 복잡해 보임.
	square(3);      //타입을 생략 - 쉬워 보임.(함수 인자로 타입 추론)

	List<int> s1(10, 0); //타입 전달
	List s2(10, 0); //타입 생략
					// 클래스 템플릿 생성자 두번째 인자로 T를 추론?
					// C++17 부터는 클래스 템플릿 생성자로 타입 추론 가능 - ok
					// C++17 이전에는 클래스 템플릿 생성자로 타입 추론 못함 에러..

//	auto s3 = make_list<int>(10, 0); //정확한 표기법- 타입전달
	auto s4 = make_list(10, 0);	//함수 템플릿은 C++98 부터 타입생략 가능
}







