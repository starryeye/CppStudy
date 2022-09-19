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
//==============================================
// Stream ���� �Ļ��� PipeStream�� ����� ���ô�.

class PipeStream : public Stream
{
	Buffer buff{ 4096 }; // 4k ����
public:
	// Stream�� ����Ʈ �����ڰ� �����Ƿ� �Ļ� Ŭ�������� ���������
	// ��� Ŭ���� �����ڸ� ȣ���ؾ��Ѵ�.

	//�Ʒ� �ڵ��� ������
	// -> �׻� �ɹ� ������ ���� ��� Ŭ���� �����ڰ� ���� ȣ��ȴ�.
	// -> ���� �ɹ� �����͸� ��� Ŭ���� �����ڿ� �����ϸ� �ȵȴ�.
	// -> �ʱ�ȭ ���� ���� ���۸� ��� Ŭ������ ����ϰ� �ȴ�..
	PipeStream() : Stream(buff) {}

//	PipeStream() {} //�����Ϸ���.. PipeStream() : Stream() {} ����..
					///							--> Stream�� ����Ʈ �����ڰ� �����Ƿ� ����
};

int main()
{
//	Buffer buff(1024);
//	Stream stream(buff);

	PipeStream ps;
	//�ʱ�ȭ ���� ��� ���� �Ǵ� ������ �ִ�..
}




