#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	//복사 생성자
	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}

	//move 생성자
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object obj1;
	Object obj2 = std::move(obj1);

	// 핵심 : obj3 은 상수 객체 이다.
	const Object obj3;
	Object obj4 = std::move(obj3);  // 복사로 동작한다..
									//상수 객체는 move될수 없다.
									//상수 객체의 내부 자원은.. 임의로 파괴(수정)할수 없기 때문.
									//
									//
									// 복사 생성자는 r/l value모두 받을 수 있다.
									//static_cast<obj3의타입&&>(obj3);
									//static_cast<const Object&&>(obj3);

}
