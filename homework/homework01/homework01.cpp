#include <iostream>
using namespace std;

int StringCount(const char* _str)
{
	int count = 0;
	while (_str[count])
	{
		count++;
	}
	return count;
}

int NumberCount(int _Value)
{
	// /(나누기를 최대한) 연산을 사용하세요.
	// 
	// 내가 한 버전
   /* int Result = 0;
	int DevisionNum = 1;
	while (true)
	{
		if (_Value / DevisionNum==0)
		{
			break;
		}
		DevisionNum *= 10;
		Result++;
	}

	return Result;*/

	// 힌트주셔서 다시 푼것
	int Result = 0;
	while (true)
	{
		_Value /= 10;
		Result++;
		if (_Value == 0)
		{
			break;
		}
	}
	return Result;
}

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
	int count01 = StringCount(_Value0);
	int count02 = StringCount(_Value1);

	for (int i = 0; i < count01; i++) 
	{
		_Buffer[i] = _Value0[i];
	}
	for (int i = 0; i < count02; i++)
	{
		_Buffer[i+count01] = _Value1[i];
	}


}
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int count = NumberCount(_Value); //value 자릿수
	if (count > BufferSize)
	{
		return;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		//	3712 % 10 = 2 가 Buffer[3]에 들어가고 _value 371
		//  371 % 10 = 1 가 Buffer[2]에 들어가고 _value 37
		//  37 % 10 = 7 가 Buffer[1]에 들어가고 _value 3
		//  3 % 10 = 3 가 Buffer[0]에 들어가고 _value 0
		int result = _Value % 10;
		Buffer[i] = result + '0';
		_Value /= 10;

	}
}




int main()
{
	// [B][B][B][B][0]

	char Arr[100] = {};

	PlusString(Arr, 100, "cccccccccccc", "BBBB");

	std::cout << "Hello World!\n";

	int a = 0;
}