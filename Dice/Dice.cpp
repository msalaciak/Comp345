#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<random>
#include <map>
using namespace std;
#include "Dice.h"



Dice::Dice() 
{
	cout << "Enter playerNumber \n";
	cin >> playerNumber;
	vector<int> diceContainer;
	
	
	

}

void Dice ::rollDice()
{
	srand(time(0));
	cout << "Choose between 1-3 dice, please enter amount of dice: ";
	cin >> amountOfDice;
	
	if (amountOfDice == 1) 
	{

		diceValue = (rand() % 6 + 1);
		
		

		
	}
	else if (amountOfDice == 2) 
	{
		diceValue = (rand() % 6 + 1) + (rand() % 6 + 1);
		
		
		
		
	}

	else if (amountOfDice == 3) 
	{
		diceValue = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
		

	}

	cout << diceValue << endl;
	cout << "\n" << endl;
	

	
}

int Dice::getDiceValue() 
{

	return diceValue;
}



void Dice::storeDice(int diceValue)
{
	

	diceContainer.push_back(diceValue);

}

void Dice::diceStats()
{
	
	
	cout << "Dice roll percentages for player " << playerNumber  << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "total number of rolls " << diceContainer.size() << "\n" << endl;

	
	map<int, int> diceCount;

	for (int i = 0; i < diceContainer.size(); i++)
	{
		diceCount[diceContainer[i]]++;
	}

	for (auto const &x : diceCount)
	{
		double first = x.first;
		double repeat = x.second;
		cout << "The number " << first << " appears " << (repeat/ diceContainer.size())*100 << " % \n" << endl;

	}
	
}

void Dice::diceContainerValues()
{
	cout << "Dice container values for player "<<playerNumber  << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (int i = 0; i < diceContainer.size(); i++) 
	{
		cout << diceContainer[i] << "\n" <<endl;
	}


}

int Dice::getPlayerNumber() 
{
	return playerNumber;
}







