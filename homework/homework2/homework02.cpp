// 001_NumberCount.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>

// ���� ����
// 0 �̿��� ����� �ڸ����� ����.
int NumberCount(int _Value)
{
	// /(�����⸦ �ִ���) ������ ����ϼ���.
	// 
	// ���� �� ����
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

	// ��Ʈ�ּż� �ٽ� Ǭ��
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

// �ص� �ǰ� ���ص� �˴ϴ�.
// �� �������� ����
// _Value �� �־��ָ� Buffer�� 
// ���ڸ� ���ڿ��� ����� �Լ�.
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int count = NumberCount(_Value); //value �ڸ���
	if (count > BufferSize)
	{
		return;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		//	3712 % 10 = 2 �� Buffer[3]�� ���� _value 371
		//  371 % 10 = 1 �� Buffer[2]�� ���� _value 37
		//  37 % 10 = 7 �� Buffer[1]�� ���� _value 3
		//  3 % 10 = 3 �� Buffer[0]�� ���� _value 0
		
		int result = _Value % 10;
		Buffer[i] = result + '0';
		_Value /= 10;

	}

	
}

int main()
{
	// 5
	int Result0 = NumberCount(12358);
	// 4
	int Result1 = NumberCount(5258);
	// 7
	int Result2 = NumberCount(5258111);

	// 0�� ��

	char Buffer1[100] = { 0 };

	NumberToString(Buffer1, 100, 3712);
	char Buffer2[100] = { 0 };
	NumberToString(Buffer2, 100, 37123213);
	// Buffer == "3712"

	int a = 0;

}
