// conversion function pointer

int main()
{
	int k = 0;

	//�ٽ� 1. ���� ǥ������ �Լ� �����ͷ� ��ȯ �����ϴ�.
	int(*f1)(int, int) = [](int a, int b) { return a + b; };

	//�ٽ� 2. �׷���.. ĸ���� ���� ǥ������ �Լ� ������ ��ȯ�� �ȵȴ�.
	int(*f2)(int, int) = [k](int a, int b) { return a + b + k; }; //error
}