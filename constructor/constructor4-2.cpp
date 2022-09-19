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
//C++ 표준의 ostream 클래스를 만들때 사용한 방법이다.
//C++ 진영에서 "Base From Member" 라는 이름을 가진 기법이다.
class PipeBuffer
{
protected:
	Buffer buff{ 4096 };
};

class PipeStream : public PipeBuffer, public Stream //pipebuffer를 앞에 배치하여 먼저 생성되도록 함
{
public:
	PipeStream() : Stream(buff) {} // : PipeBuffer(), Stream(buff)

};

int main()
{


	PipeStream ps;
}




