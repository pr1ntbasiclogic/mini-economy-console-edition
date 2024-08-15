#include "player.hpp"
#include "mainMenu.hpp"
#include "TransNeffects.hpp"


void playerCreationMenu()
{
	int playerSelectionPart = 0;
	char goBack;
	using std::cout;
	using std::cin;
	using std::string;

	player p1;

	string temp_playerFirstName;
	string temp_playerLastName;

	int temp_keyStat;

	int temp_playerSex;
	int temp_hairColor;
	int temp_playerLooks;
	int temp_clothes;

	playerSelectionAlgo:
	if (playerSelectionPart == 0)
	{
		nameselection_First:
		refreshNClear();
		screenline("What is your first name? (Eg. John):");
		std::getline(std::cin >> std::ws, temp_playerFirstName);
		if (p1.changePlayerFirstName(temp_playerFirstName) == false)
		{
			cout << "!! use only characters in your name !! (Eg. a,b,c)";
			goto nameselection_First;
		}
		else
		{
			p1.changePlayerFirstName(temp_playerFirstName);
			playerSelectionPart += 1;
		}
	}
	
	if (playerSelectionPart == 1)
	{
		nameselection_Last:
		refreshNClear();
		screenline("What is your last name? (Eg. Farmer):");
		std::getline(std::cin >> std::ws, temp_playerLastName);
		if (p1.changePlayerLastName(temp_playerLastName) == false)
		{
			cout << "!! use only characters in your name !! (Eg. a,b,c)";
			goto nameselection_Last;
		}
		else
		{
			p1.changePlayerLastName(temp_playerLastName);
			playerSelectionPart += 1;
		}
	}

	if (playerSelectionPart == 2)
	{
		refreshNClear();
		screenline("What is your key stat? (Eg. 1,2,3,4)");
		std::cout << "[1.] High Roller (less prone to stress.)\n";
		std::cout << "[2.] Charm (5% easier to persuade people for deals.)\n";
		std::cout << "[3.] Greed (10% more capital gain on everything. more bad events.)\n";
		std::cout << "[4.] Empty (nothing special about you.)\n";
		std::cin >> temp_keyStat;
		p1.changeKeyStat(temp_keyStat);
		playerSelectionPart += 1;
	}
	if (playerSelectionPart == 3)
	{
		refreshNClear();
		screenline("What is your Sex? (Eg. 1,2,3,4");
		std::cout << "[1.] Male\n";
		std::cout << "[2.] Female\n";
		std::cout << "[3.] Non-binary\n";
		std::cin >> temp_playerSex;

		refreshNClear();
		screenline("What is your hair color? (Eg. 1,2,3,4)");
		std::cout << "[1.] Blonde\n";
		std::cout << "[2.] Black\n";
		std::cout << "[3.] Brown\n";
		std::cout << "[4.] Amber\n";
		std::cout << "[5.] Bald\n";
		std::cin >> temp_hairColor;

		refreshNClear();
		screenline("What is your looks? (Eg. 1,2,3,4)");
		std::cout << "[1.] Exquisite\n";
		std::cout << "[2.] Average\n";
		std::cout << "[3.] Homely\n";
		std::cout << "[4.] Undescribable\n";
		std::cin >> temp_playerLooks;

		refreshNClear();
		screenline("What is your starting clothes? (Eg. 1,2,3,4)");
		std::cout << "[1.] Rags\n";
		std::cout << "[2.] No clothes\n";
		std::cin >> temp_clothes;

		playerSelectionPart += 1;
	}
	if (playerSelectionPart == 4)
	{
		screenline("Would you like to change your stats again? (Eg. Y,N)");
		std::cout << "Name: " << temp_playerFirstName << ' ' << temp_playerLastName << '\n';
		
		switch (temp_keyStat)
		{
			case 1:
				std::cout << "Key Stat: High Roller" << '\n';
				break;
			case 2:
				std::cout << "Key Stat: Charm" << '\n';
				break;
			case 3:
				std::cout << "Key Stat: Greed" << '\n';
				break;
			default:
				std::cout << "Key Stat: Empty" << '\n';
				break;
		}

		switch (temp_playerSex)
		{
		case 1:
			std::cout << "Sex: Male" << '\n';
			break;
		case 2:
			std::cout << "Sex: Female" << '\n';
			break;
		default:
			std::cout << "Sex: Non-Binary" << '\n';
			break;
		}

		switch (temp_hairColor)
		{
		case 1:
			std::cout << "Hair Color: Blonde" << '\n';
			break;
		case 2:
			std::cout << "Hair Color: Black" << '\n';
			break;
		case 3:
			std::cout << "Hair Color: Brown" << '\n';
			break;
		case 4:
			std::cout << "Hair Color: Amber" << '\n';
			break;
		default:
			std::cout << "Hair Color: Bald" << '\n';
			break;
		}

		switch (temp_playerLooks)
		{
		case 1:
			std::cout << "Looks: Exquisite" << '\n';
			break;
		case 2:
			std::cout << "Looks: Average" << '\n';
			break;
		case 3:
			std::cout << "Looks: Homely" << '\n';
			break;
		default:
			std::cout << "Looks: Undescribable" << '\n';
			break;
		}

		switch (temp_clothes)
		{
		case 1:
			std::cout << "Clothes: Rags" << '\n';
			break;
		case 2:
			std::cout << "Clothes: None" << '\n';
			break;
		default:
			std::cout << "Clothes: Rags" << '\n';
			break;
		}

		std::cin >> goBack;
		if (goBack == 'Y' or goBack == 'y')
		{
			playerSelectionPart = 0;
			refreshNClear();
			goto playerSelectionAlgo;
		}
		else
		{
			playerSelectionPart += 1;
			refreshNClear();
		}
	}
	if (playerSelectionPart == 5)
	{
		p1.changeCharacter(temp_playerSex, temp_hairColor, temp_playerLooks, temp_clothes);
		screenline("now, describe your player.");
		p1.describePlayer();	
	}
}

