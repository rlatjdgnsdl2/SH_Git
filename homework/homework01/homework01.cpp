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




int main()
{
	// [B][B][B][B][0]

	int Count = StringCount("BBBB");

	int a = 0;
}