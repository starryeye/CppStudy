// F.53: Avoid capturing by reference in lambdas that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>

std::function<int(int, int)> f;

void foo()
{
	//�ٽ� 1. ���� ǥ������ auto �� �ƴ϶� std::function���� ������ �ִ�.
	auto f1 = [](int a, int b) {return a + b; };

	std::function<int(int, int)> f2 = [](int a, int b) {return a + b; };
}

int main()
{
	//���������θ� ������� �ʴ� ����ǥ������
	//���������� reference capture ���� ����..
	int n = 0;

//	f = [n](int a, int b) {return a + b + n; }; //ok �׻� �����ϴ�.
											//n�� �ƴ϶� n�� �� 0�� ����

	f = [&n](int a, int b) {return a + b + n; };
								//reference capture.
								// n ��ü�� ����(�ּ�)�� ĸ��
}//<- �̼��� n�� �ı�. ������.. f�� �����̹Ƿ� �ٸ� ������ ��밡��
	// f�� ĸ���� n�� "Dangling reference" �̴�.
	//-> ����

int main()
{
	foo();
	f(1, 2); //���� .. f�� ĸ���� n�� �̹� �ı� �Ǿ���
}