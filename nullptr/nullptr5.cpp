#include <iostream>

int main()
{
	// 1. ���α׷����� ���Ǵ� "��" ���� ���ͷ�(literal)�̶�� �մϴ�.
	// 2. ��� ���ͷ��� Ÿ���� �ֽ��ϴ�.
	10;			//int
	3.4;		//double
	3.4f;		//float
	"hello";	//const char[6]

	true;		//"��"�� ��Ÿ���� ���ͷ��̰�, ��ӵ� �ܾ�(Ű����)
				//bool
	nullptr;	//std::nullptr_t ��� Ÿ���̴�. Ÿ���̸� ���

	// std::nullptr_t Ÿ���� "��� ������ �����ͷ� �Ͻ��� ����ȯ�ȴ�"��
	// ������ �ִ�.
	std::nullptr_t x = nullptr;

	// ���� x�� nullptr ó�� ������ �ʱ�ȭ�� ��밡���ϴ�.
	int* p1 = x;
	char* p2 = x;

}