#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	void useBuffer() { std::cout << "���� ���" << std::endl; }

	~Buffer() { delete[] buff; }
	// ��� �� ���Կ����ڴ� ����..
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//C++ ǥ���� ostream Ŭ������ ���鶧 ����� ����̴�.
//C++ �������� "Base From Member" ��� �̸��� ���� ����̴�.
class PipeBuffer
{
protected:
	Buffer buff{ 4096 };
};

class PipeStream : public PipeBuffer, public Stream //pipebuffer�� �տ� ��ġ�Ͽ� ���� �����ǵ��� ��
{
public:
	PipeStream() : Stream(buff) {} // : PipeBuffer(), Stream(buff)

};

int main()
{


	PipeStream ps;
}




