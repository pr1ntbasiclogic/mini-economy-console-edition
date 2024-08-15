#pragma once
#include <iostream>
#include <string>
using std::string;

class player 
{
	bool stat_HighRoller = false;
	bool stat_Charm = false;
	bool stat_Greed = false;

	int stat_playerHairColor{};
	int stat_playerLooks{};
	int stat_PlayerClothes{};
	
	int stat_playerSex{};

	bool stat_Bankrupt = false;
	int  stat_playerJob = 0;
	int stat_playerStressAmount = 0;
	int stat_playerMoneyAmount = 0;
	int stat_playerDebtAmount = 0;
	int stat_playerPropertyAmount = 0;

	// These emulate above stats, but these are just for description texts, hence d_.
	string playerFirstName;
	string playerLastName;

	string d_keystat;
	
	string d_phc;
	string d_prl;
	string d_prc;

	string d_prs;
	string d_prt; //player title, Mr. Ms. Mx (mx = non binary.)
	string d_prj;
public:
	

	int getPlayer_MA();
	void addPlayer_MA(int addedvalue);
	void subPlayer_MA(int subedvalue);

	int getPlayer_DA();
	void subPlayer_DA(int subedvalue);

	int getPlayer_PA();
	void addPlayer_PA(int addedvalue);
	void subPlayer_PA(int subedvalue);

	int getPlayer_SA();
	void addPlayer_SA(int addedvalue);
	void subPlayer_SA(int subedvalue);

	bool changePlayerFirstName(string temp_playerFirstName); //checks to see if the given names are even strings.
	bool changePlayerLastName(string temp_playerLastName); //checks to see if the given names are even strings. x2
	void changeKeyStat(int temp_keyStat);
	void changeCharacter(int temp_playerSex, int temp_hairColor, int temp_playerLooks, int temp_clothes); //non changable stats.
	void describePlayer();
	void describePlayerAssests();
};
