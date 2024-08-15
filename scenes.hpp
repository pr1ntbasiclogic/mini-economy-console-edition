/*
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <tuple>

using std::string;

class StockMarket
{
	std::map<int, std::tuple< string, int, int>> stocks;
public:
	void addStock(int stockKey, string stockName, int stockPrice, int stockSellPrice);
	int getCurrentStockMarket();
	int getAvailableStockMarkets();
};

class City
{
	std::map<int, std::tuple<string, int>> cities;
public:
	void addCity(int cityKey, string cityName, int cityPopulation);
	int getCurrentCity();
	int getAvailableCities();
};

class Building : City
{
	std::map<int, std::tuple<string>> buildings;
	int currentBuilding;
public:
	void addBuilding(int buildingKey, string buildingName);
	int getCurrentBuilding();
	int getAvailableBuildings();
};

class Casino : Building
{
	std::map<int, std::tuple<string>> casinos;
	int currentCasino;
public:
	void addCasino(int casinoKey, string casinoName);
	int getCurrentCasino();
	int getAvailableCasinos();
};

class Bank : Building
{
	std::map<int, std::tuple<string>> banks;
	int currentBank;
public:
	void addBank(int bankKey, string bankName);
	int getCurrentBank();
	int getAvailableBanks();
};

class HOA : Building
{
	std::map<int, std::tuple<string, int, int >> HOAs;
	int currentHOA;
public:
	void addHOA(int hoaKey, string hoaName, int hoaPrice, int hoaSellPrice);
	int getCurrentHOA();
	int getAvailableHOAs();
};
*/