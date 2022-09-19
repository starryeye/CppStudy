#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) const { return buff[idx]; } //const
};

int main()
{
	int n;
	vector<int> v1(10);
	const vector<int> v2(10);

	//				//의도한 것		//현재 동작
	v1[0] = 10;		//ok			//ok
	n = v1[0];		//ok			//ok

	v2[0] = 10;		//error			//ok
	n = v2[0];		//ok			//ok
}