#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// 1. non-const ������ �Լ� ȣ���� lvalue �� �ǰ� �ؾ��Ѵ�.
	// -> reference ��ȯ
	T& operator[](int idx) { return buff[idx]; }
	
	// 2. const ������ �Լ� ȣ���� ��ȣ�� ���ʿ� �ü� ���� �ؾ��Ѵ�.
	// ��� 1. value ��ȯ
	// -> temporary(rvalue)�� ��ȯ
	// -> �ּ� �����ڸ� ��� �� �� ���� ������ "&v2[0]" ���� �ڵ带 ������.
	// -> �ӽð�ü�� lvalue reference�� �ּҸ� �����Ѵ�.
	//T operator[](int idx) const { return buff[idx]; } //const �߸��� ���
	
	// ��� 2. const reference ��ȯ
	// -> lvalue ��ȯ, "&v2[0]" ��� ����
	// -> ��, const reference �̹Ƿ� ��ȣ ���ʿ��� �ü� ����. "v2[0] = 10" error
	const T& operator[](int idx) const { return buff[idx]; } //const
};

int main()
{
	int n;
	vector<int> v1(10);
	const vector<int> v2(10);

	//				//�ǵ��� ��		//���� ����
	v1[0] = 10;		//ok			//ok
	n = v1[0];		//ok			//ok

	v2[0] = 10;		//error			//error
	n = v2[0];		//ok			//ok

	auto p = &v2[0]; // �Ǿ�� �Ѵ�.
						//��� vector�� ù��° ����� �ּ� ���ϱ�
						//����, [] �� const ������ ��ȯ ����
						//lvalue�̾�� �Ѵ�.
						//��, ��ȣ�� ���ʿ��� �� �� ����� �ϹǷ�
						//"const lvalue"
}