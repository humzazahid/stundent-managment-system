#include <iostream>
#include <math.h>
#include <windows.h>                 
#include"login.h"
#include"records.h"
#include <iomanip>
#include <limits>
#include<fstream>
#include<string>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>                  // For isalpha() function
using namespace std;
void main()
{
again:
	cout << "Plz insert 4digit security chk password";
	Sleep(5000);
	system("cls");
	string str, pin;
	int flag = 0;
	do {
		ifstream outFile;
		ofstream inFile;

		outFile.open("h://data.txt");
		outFile >> str;
		if (str.empty())
		{
			goto again;
		}
		else
			flag = 1;
	} while (flag != 1);
	cout << "enter  you 4digit pin\n";
	cin >> pin;
	if (pin == str)
	{
		cout << "Welcome\n";
		system("color 0F"); 
		login();

		while (true)

		{

			system("cls");
			r.studentMenu();

		}

	}
	system("pause");
}
