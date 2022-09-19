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
//==============================================
// Stream 에서 파생된 PipeStream을 만들어 봅시다.

class PipeStream : public Stream
{
	Buffer buff{ 4096 }; // 4k 버퍼
public:
	// Stream에 디폴트 생성자가 없으므로 파생 클래스에서 명시적으로
	// 기반 클래스 생성자를 호출해야한다.

	//아래 코드의 문제점
	// -> 항상 맴버 데이터 보다 기반 클래스 생성자가 먼저 호출된다.
	// -> 절대 맴버 데이터를 기반 클래스 생성자에 전달하면 안된다.
	// -> 초기화 되지 않은 버퍼를 기반 클래스가 사용하게 된다..
	PipeStream() : Stream(buff) {}

//	PipeStream() {} //컴파일러가.. PipeStream() : Stream() {} 으로..
					///							--> Stream에 디폴트 생성자가 없으므로 에러
};

int main()
{
//	Buffer buff(1024);
//	Stream stream(buff);

	PipeStream ps;
	//초기화 전에 사용 부터 되는 문제가 있다..
}




