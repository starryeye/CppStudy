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
	// �ٽ�
	// 1. move �迭�� ���鶧�� �ǵ��� ���ܰ� �߻����� �ʵ��� �������Ѵ�.
	// 2. ���ܰ� ������ �����Ϸ����� �˷��־�� �Ѵ�.
	// noexcept : �ش� �Լ��� ���ܰ� ������ �����Ϸ����� �˸��� Ű����
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object obj1;
	Object obj2 = obj1; // �׻� ���� ������ ���
	Object obj3 = std::move(obj2); //�׻� move ������ ���
	Object obj4 = std::move_if_noexcept(obj3);
		//move �����ڿ� ���ܰ� ������(noexcept�� �پ��ִ°��) move ������
		//�׷��� ������ ���� �����ڸ� ���



	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10);	// �̼����� ������ �����غ��ô�.
					//10��¥�� ������ ���� �Ҵ�
					//�װ����� 5ȸ�� copy�� �̷������. (noexcept Ű���� ������)
					//�װ����� 5ȸ�� move�� �̷������. (noexcept Ű���尡 ������)

	//move�� �����Ҷ�.. ���� �߻��� ������ ������ ���ư��� ����.
	// -> �׷��� move�� ���ܰ� ����� �Ҽ� ����.. 
	//copy�� Ʈ����� rollback�� ����ȴ�.

	std::cout << "----------------" << std::endl;
}

//���..
//vector�� ����Ҷ��� noexcept Ű���带 �ٿ��� ��������� ���� �ִ�.
//�Ⱥ��̸� �׳� copy�� �Ǿ����.
