#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	//���� ������
	Object(const Object&)
	{
		std::cout << "copy" << std::endl;
	}

	//move ������
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object obj1;
	Object obj2 = std::move(obj1);

	// �ٽ� : obj3 �� ��� ��ü �̴�.
	const Object obj3;
	Object obj4 = std::move(obj3);  // ����� �����Ѵ�..
									//��� ��ü�� move�ɼ� ����.
									//��� ��ü�� ���� �ڿ���.. ���Ƿ� �ı�(����)�Ҽ� ���� ����.
									//
									//
									// ���� �����ڴ� r/l value��� ���� �� �ִ�.
									//static_cast<obj3��Ÿ��&&>(obj3);
									//static_cast<const Object&&>(obj3);

}
