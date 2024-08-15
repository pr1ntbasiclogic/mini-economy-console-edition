#include "TransNeffects.hpp"
#include <iostream>
#include <Windows.h>

using std::string;
using std::cout;

void refreshNClear()
{
	cout << '\n';
	for (int i = 0; i < 3; i++)
	{
		cout << '.' << ' ';
		Sleep(500);
	}
	system("cls");
}

void screenline(string forText) //automatically structures a underline based on given string size.
{
	int lineSize = 0;
	cout << forText;
	for (char c : forText)
	{
		lineSize += 1;
	}
	cout << '\n';
	for (int i = 0; i < lineSize; ++i)
	{
		cout << '-';
	}
	cout << '\n';
}
