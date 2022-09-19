#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }

	~Buffer() { delete[] buff; }
	// 목사 및 대입연산자는 생략..
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};

int main()
{
	Buffer buff(1024);
	Stream stream(buff);
}




