// ES.47: Use nullptr rather than 0 or NULL

int main()
{
	// null 포인터가 필요하면 0 대신 nullptr 사용하자
	int* p1 = 0;		//C++ 이전 스타일, bad
	int* p2 = nullptr;  //good

	// 장점 1. 가독성
	auto ret = fn(); //어떤 fn() 함수의 리턴 값을 auto로 받았다..

	if (ret == 0) {} // 이 코드만으로 ret가 포인터 인지 정수인지 알수 없다.
	if (ret == nullptr) {} // ret가 포인터 라고 예측 가능
}
