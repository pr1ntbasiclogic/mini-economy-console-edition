#include <iostream>
#include <string>
#include "mainMenu.hpp"
#include "Windows.h"

using std::cout;
using std::cin;
using std::string;

bool gameStarted = false;

int main()
{
	std::string mainMenu_option;

	cout << "start [Y/N]";
	std::getline(std::cin >> std::ws, mainMenu_option);
	
	if (mainMenu_option == "Y" or mainMenu_option == "y")
	{
		gameStarted = true;
		playerCreationMenu();
		
	}
	else if (mainMenu_option == "N" or mainMenu_option == "n")
	{
		cout << '\n';
		cout << "!! game closed !!";
		return 0;
	}
	else
	{
		cout << '\n';
		cout << "!! incorrect entry, type 'Y' or 'N'. Then press [enter] key. !!";
	}

	return 0;
}

