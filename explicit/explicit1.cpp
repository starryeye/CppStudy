// C46.���ڰ� �Ѱ��� �����ڴ� explicit �� �ϴ� ���� ����.

class Vector
{
public:
	//explicit ������ : ���� �ʱ�ȭ�� �����ϰ� �����ʱ�ȭ�� ����� �� ����.
	//���ڰ� �Ѱ��� �����ڴ� "explicit"�� �����ϴ� ���� �׻� �����ϴ�.
	explicit Vector(int sz) {}
};

void fn(Vector v) {}

int main()
{
	//�ٽ� 1. �����ڷ� int �Ѱ��� ������ �Ʒ�ó�� 4���� ���·� ��ü ������ ����
	Vector v1(10);		//direct initialization : "="�� ���� ��
	Vector v2 = 10;		//direct initialization : "="�� �ִ� ��
	Vector v3{ 10 };	//C++11, direct
	Vector v4 = { 10 }; //C++11, copy

	//�ٽ� 2. �Լ��� ���� ������ "���� �ʱ�ȭ" �̴�.
	fn(10); // -> fn�� ���ڴ�..
			// Vector v = 10 �� ������ ���޵�.
			//Vector�� ����ϴµ�.. 10�� �൵ �Ǵ°�..
			//�ǵ����� ���� �ڵ��� ��찡 ����..
			//-> explicit Ű���� �߰�����..
}