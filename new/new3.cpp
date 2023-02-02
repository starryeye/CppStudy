#include <iostream>
#include <vector>
/*
int main()
{
	std::vector<int> v(10);

	v.resize(7); // ���� ������ ������ ���ô�.
					//���� �޸� �׳� ���, size ������ ����

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

	v.resize(3); //�پ�� 2���� �޸� ��ü�� ���� ���� �ʴ´�.
				//������, �Ҹ��ڴ� ȣ���ؾ� �Ѵ�.
				//�Ҹ��ڸ� ȣ���ϴ� ����� �ʿ��ϴ�.

	std::cout << "---------------" << std::endl;

	v.resize(4); //�þ �Ѱ��� ���� �޸𸮴� �̹� �ִ�.
				//�����ڸ� �ٽ� ȣ���ؼ� �ʱ�ȭ ����..
				//�����ڸ� ȣ���ϴ� ����� �ʿ��ϴ�.

	std::cout << "---------------" << std::endl;
}