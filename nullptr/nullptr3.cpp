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

//	Object obj(0, 0); // 0�� ������(2��° ����)�� ���� ���� ����
//	v.push_back(obj);

//	v.emplace_back(0, 0); //�Ϻ��� ������ ����ϴ� �Լ�����
							//������ �ǹ��� 0(null)�� ���� �ȵȴ�.
							//2��° ���� ������ ����..

	v.emplace_back(0, nullptr); //ok..

}




