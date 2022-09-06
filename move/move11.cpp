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
	// 핵심
	// 1. move 계열을 만들때는 되도록 예외가 발생하지 않도록 만들어야한다.
	// 2. 예외가 없음을 컴파일러에게 알려주어야 한다.
	// noexcept : 해당 함수가 예외가 없음을 컴파일러에게 알리는 키워드
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object obj1;
	Object obj2 = obj1; // 항상 복사 생성자 사용
	Object obj3 = std::move(obj2); //항상 move 생성자 사용
	Object obj4 = std::move_if_noexcept(obj3);
		//move 생성자에 예외가 없으면(noexcept가 붙어있는경우) move 생성자
		//그렇지 않으면 복사 생성자를 사용



	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10);	// 이순간의 원리를 생각해봅시다.
					//10개짜리 공간을 새로 할당
					//그공간에 5회의 copy가 이루어진다. (noexcept 키워드 없을때)
					//그공간에 5회의 move가 이루어진다. (noexcept 키워드가 있을때)

	//move를 진행할때.. 예외 발생시 원래의 값으로 돌아갈수 없다.
	// -> 그래서 move는 예외가 없어야 할수 있음.. 
	//copy는 트랜잭션 rollback이 보장된다.

	std::cout << "----------------" << std::endl;
}

//결론..
//vector를 사용할때는 noexcept 키워드를 붙여야 성능향상을 볼수 있다.
//안붙이면 그냥 copy가 되어버림.
