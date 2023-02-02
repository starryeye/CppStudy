#include <iostream>
#include <vector>
/*
int main()
{
	std::vector<int> v(10);

	v.resize(7); // 구현 원리를 생각해 봅시다.
					//기존 메모리 그냥 사용, size 변수만 변경

	std::cout << v.size() << std::endl; //7
	std::cout << v.capacity() << std::endl; //10
}
*/
class DBConnect
{
public:
	DBConnect() { std::cout << "Connect DB" << std::endl; }
	~DBConnect() { std::cout << "Disconnect DB" << std::endl; }
};

int main()
{
	std::vector<DBConnect> v(5);

	std::cout << "---------------" << std::endl;

	v.resize(3); //줄어든 2개는 메모리 자체는 해지 되지 않는다.
				//하지만, 소멸자는 호출해야 한다.
				//소멸자만 호출하는 기술이 필요하다.

	std::cout << "---------------" << std::endl;

	v.resize(4); //늘어난 한개를 위한 메모리는 이미 있다.
				//생성자만 다시 호출해서 초기화 하자..
				//생성자만 호출하는 기술이 필요하다.

	std::cout << "---------------" << std::endl;
}