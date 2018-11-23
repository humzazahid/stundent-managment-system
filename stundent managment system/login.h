#include"time.h";
#include"load.h";
#include<iostream>
#include <conio.h>
using namespace std;
void mainEntrance()
{
	cout << "     **************************************************************" << endl;
	cout << "        HUMZA-ZAHID 01-131162-008,FAIZAN-UL-HAQ 01-131162-037      " << endl;
	cout << "     **************************************************************" << endl;
	cout << "                       DATA STRUCTURES PROJECT  BSE-3A             " << endl;
	cout << "     **************************************************************" << endl;
	cout << "	    	       	University database management system				" << endl;
	cout << "     **************************************************************" << endl;
}

void login()
{
	system("cls");

	string username = "";
	string password = "";
	char ch, ch2, retry;
	int i = 0, j = 0;
	mainEntrance();
	time();
	cout << "(LOGIN)\n";
	cout << "Enter Username: ";

	ch2 = _getch();
	while (ch2 != 13) {                  // gets input until 'Enter' key is pressed

		if (ch2 == '\b') {
			if (username.size() > 0) {
				username.erase(username.begin() + username.size() - 1);
				cout << "\b \b";
				j--;
			}
			ch2 = _getch();
		}
		else {
			if (j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = _getch();
				j++;
			}
			else {
				ch2 = _getch();
			}
		}
	}
	cout << "\nEnter Password :";
	ch = _getch();
	while (ch != 13) {                  // gets input until 'Enter' key is pressed

		if (ch == '\b') {
			if (password.size() > 0) {
				password.erase(password.begin() + password.size() - 1);
				cout << "\b \b";
				i--;
			}
			ch = _getch();
		}
		else {
			if (i<10)
			{
				password.push_back(ch);
				cout << "*"; 					  // For showing stars instead of actual alphabets
				ch = _getch();
				i++;
			}
			else {
				ch = _getch();
			}
		}
	}
	if (username == "humza" && password == "12345")
	{
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		cout << "\n\n\t\t Now Loading: ";
		loading();
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;
		if (retry == 'r' || retry == 'R')
		{
			system("cls");
			login();
		}
		else
		{
			exit(0);
		}
	}
}