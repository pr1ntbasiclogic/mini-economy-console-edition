#include "player.hpp"
using std::cout;

//money
int player::getPlayer_MA() {
	return stat_playerMoneyAmount;
}

void player::addPlayer_MA(int addedvalue) {
	stat_playerMoneyAmount += addedvalue;
}
void player::subPlayer_MA(int subedvalue) {
	if (subedvalue > stat_playerMoneyAmount)
	{
		subedvalue -= stat_playerMoneyAmount;
		stat_playerMoneyAmount = 0;
		stat_playerDebtAmount += subedvalue;
	}
	else
	{
		stat_playerMoneyAmount -= subedvalue;
	}
}

//debt
int player::getPlayer_DA() {
	return stat_playerDebtAmount;
}

void player::subPlayer_DA(int subedvalue) {
	stat_playerDebtAmount -= subedvalue;
}

//property
int player::getPlayer_PA() {
	return stat_playerPropertyAmount;
}
void player::addPlayer_PA(int newProp) {
	stat_playerPropertyAmount += newProp;
}
void player::subPlayer_PA(int oldProp) {
	stat_playerPropertyAmount -= oldProp;
}

//stress
int player::getPlayer_SA() {
	return stat_playerStressAmount;

}
void player::addPlayer_SA(int newamount) {
	stat_playerStressAmount += newamount;
}
void player::subPlayer_SA(int oldamount) {
	stat_playerStressAmount -= oldamount;
}




bool player::changePlayerFirstName(string temp_playerFirstName) //checks to see if the given names are even strings.
{
	for (char c : temp_playerFirstName)
	{
		if (isalpha(c) == false)
		{
			return false;
		}
	}
	playerFirstName = temp_playerFirstName;
	return true;
}

bool player::changePlayerLastName(string temp_playerLastName) //checks to see if the given names are even strings. x2
{
	for (char c : temp_playerLastName)
	{
		if (isalpha(c) == false)
		{
			return false;
		}
	}
	playerLastName = temp_playerLastName;
	return true;
}

void player::changeKeyStat(int temp_keyStat)
{
	switch (temp_keyStat)
	{
	case 1:
		stat_HighRoller = true;
		d_keystat = "High Roller";
		//set stat_HighRoller = true;
		break;
	case 2:
		stat_Charm = true;
		d_keystat = "Charm";
		//set stat_Charm = true;
		break;
	case 3:
		stat_Greed = true;
		d_keystat = "Greed";
		break;
	default:
		d_keystat = "Empty";
		//set stats ALL to false
		break;
	}
}

void player::changeCharacter(int temp_playerSex, int temp_hairColor, int temp_playerLooks, int temp_clothes) //non changable stats.
{
	//please, for the love of god. set all these 'TEMP' values to nothing when they are finished being used.
	switch (temp_playerSex)
	{
	case 1:
		stat_playerSex = 1;
		d_prs = "male";
		d_prt = "Mr.";
		break;
	case 2:
		stat_playerSex = 2;
		d_prs = "female";
		d_prt = "Ms.";
		break;
	default:
		stat_playerSex = 0;
		d_prs = "non-binary";
		d_prt = "Mx.";
		break;
	}

	switch (temp_hairColor)
	{
	case 1:
		stat_playerHairColor = 1;
		d_phc = "blonde";
		break;
	case 2:
		stat_playerHairColor = 2;
		d_phc = "black";
		break;
	case 3:
		stat_playerHairColor = 3;
		d_phc = "brown";
		break;
	case 4:
		stat_playerHairColor = 4;
		d_phc = "amber";
		break;
	default: //more bald jokes LOL
		stat_playerHairColor = 0;
		d_phc = "bald";
		break;
	}

	switch (temp_playerLooks)
	{
	case 1:
		stat_playerLooks = 1;
		d_prl = "exquisite";
		break;
	case 2:
		stat_playerLooks = 2;
		d_prl = "average";
		break;
	case 3:
		stat_playerLooks = 3;
		d_prl = "homely";
		break;
	default:
		stat_playerLooks = 0;
		d_prl = "Undescribable";
		break;
	}

	switch (temp_clothes)
	{
	case 1:
		stat_PlayerClothes = 1;
		d_prc = "rags";
		break;
	case 2: //hardcore playthrough LOL
		stat_PlayerClothes = 2;
		d_prc = "no clothes";
		break;
	default:
		stat_PlayerClothes = 1;
		d_prc = "rags";
		break; //change clothes value to default, 1.
	}
}

void player::describePlayer()
{
	cout << d_prt << ' ' << playerLastName << " is " << d_prl << ", yet a " << d_keystat << " induced " << d_prs << '.'
		<< ' ' << playerLastName << " has " << d_phc << " hair, wearing " << d_prc << '.'; cout << '\n';
	if (stat_playerStressAmount >= 0 and stat_playerStressAmount <= 3)
	{
		cout << playerLastName << ' ' << "looks visibly happy!";
	}
	else if (stat_playerStressAmount >= 4 and stat_playerStressAmount <= 7)
	{
		cout << playerLastName << ' ' << "look's visibly stressed!";
	}
	else if (stat_playerStressAmount >= 8 and stat_playerStressAmount <= 9)
	{
		cout << playerLastName << ' ' << "look's stressed!";
	}
	else if (stat_playerStressAmount == 10)
	{
		cout << playerLastName << ' ' << "look's EXTREMELY stressed!";
	}
	else
	{
		cout << playerLastName << ' ' << "has undescribable emotions.";
	}
}

void player::describePlayerAssests()
{
	if (stat_playerJob == 0) //bad rep
	{
		cout << d_prt << ' ' << playerLastName << " works nowhere!";
	}
	else //good rep
	{
		cout << d_prt << ' ' << playerLastName << ' ' << "works at: " << d_prj;
	}
	cout << '\n';
	cout << d_prt << ' ' << playerLastName << " has: " << '$' << stat_playerMoneyAmount << " in liquidity." << '\n';
	cout << d_prt << ' ' << playerLastName << " is: " << '$' << stat_playerDebtAmount << " dollars " << "in debt." << '\n';

	if (stat_playerPropertyAmount == 0) //bad rep
	{
		cout << d_prt << ' ' << playerLastName << " has: NO property's." << '\n';
	}
	else //good rep
	{
		cout << d_prt << ' ' << playerLastName << " has: " << stat_playerPropertyAmount << " property's." << '\n';
	}
}