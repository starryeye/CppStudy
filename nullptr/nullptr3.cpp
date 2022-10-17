#include <iostream>
#include <vector>

class Object
{
public:
	Object(int n, int* p) {}
};

int main()
{
	std::vector<Object> v;

//	Object obj(0, 0); // 0을 포인터(2번째 인자)에 직접 전달 가능
//	v.push_back(obj);

//	v.emplace_back(0, 0); //완벽한 전달을 사용하는 함수에는
							//포인터 의미의 0(null)이 전달 안된다.
							//2번째 인자 때문에 에러..

	v.emplace_back(0, nullptr); //ok..

}




