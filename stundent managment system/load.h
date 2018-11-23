#include<iostream>
using namespace std;
void loading()
{
	int i;
	for (i = 0; i<5; i++)
	{
		cout << "\xdb\xdb\xdb\xdb\xdb";
		Sleep(100);
	}
	Sleep(500);
	cout << endl << endl;
}
