#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) { return buff[idx]; }
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
	n = v2[0];		//ok			//error
}