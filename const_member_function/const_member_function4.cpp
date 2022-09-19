#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] ������ ������ : ��ü�� �迭 ó�� ��� �����ϰ� �Ҷ� �ʿ�
	// -> ��κ� ������ ��ȯ�ϰ� �ȴ�.
	// -> "v[0] = 10" ó�� �Լ� ȣ���� lvalue �� �ɼ� �ְ� �ϱ� ����
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector<int> v(10);
	v[0] = 0; 
	int a = v[0];
}