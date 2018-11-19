// Team project assignment #2 - Part 4
// COMP 345: Advanced program design with C++, Fall 2018
// Written by: Martin-John Hearty
// Description: header file for the deck and hand
// ------------------------------------------------------

#include "reinforcephase.h"
#include "player.h"
#include "continent.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//implementation of the start method of the ReinforceController
void ReinforceController::start()
{
    srand((unsigned)time(0));
    
    view.presentReinforce();
    
    vector<Country*> allCountries = player->getAllCountries();
    int numOfArmiesRecieved = view.getNumOfArmiesToPlace(gameMap, player);
    
    view.displayStats(numOfArmiesRecieved, player);
    
    view.userInputCardExchange(numOfArmiesRecieved, player);
    
    view.displayStats(numOfArmiesRecieved, player);
    
    view.displayContriesPlayerOwns(allCountries, player);
    
    view.placeArmiesHuman(gameMap, allCountries, numOfArmiesRecieved , player);

}
    
    
