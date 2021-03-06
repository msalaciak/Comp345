#include "player.h"
#include "cardsdeck.h"
#include "country.h"
#include "gamemap.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void Player::attack(GameMap *gameMap) {
    strategy->attack(this, gameMap);
}

void Player::fortify(GameMap* gameMap) {
    strategy->fortify(this, gameMap);
}

void Player::reinforce(GameMap* gameMap) {
    strategy->reinforce(this, gameMap);
}

void Player::addCountry(Country *country) {
    country->setOwner(this);
    countries[country->getName()] = country;
    notifyObservers();
}


void Player::drawCard(Deck* deck) {
    deck->draw(hand);
}

void Player::rollDice(int amountOfDice) {
    dice.rollDice(amountOfDice);
}

void Player::defendRollDice(int amountOfDice) {
    dice.defendRollDice(amountOfDice);
}

void Player:: getDiceRollsAttack(int amountOfDice){
    dice.getDiceValuesAttack(amountOfDice);
}

void Player:: getDiceRollsDefend(int amountOfDice){
    dice.getDiceValuesDefend(amountOfDice);
}

void Player::transferCountryTo(string countryName, Player *player) {
    Country* toBeTransfered = countries[countryName];
    toBeTransfered->setOwner(player);
    
    map<string,Country*>::iterator it = countries.find(countryName);
    countries.erase(it);
    
    player->addCountry(toBeTransfered);
}

vector<Country*> Player::getAllCountries() {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        if(country.second->getOwner()->getPlayerId() != this->id) {
            countries.erase(country.second->getName());
        } else {
            theCountries.push_back(country.second);
        }
    }
    return theCountries;
}

vector<Country*> Player::getCountriesByContinent(string continent) {
    vector<Country*> theCountries;
    for(auto &country: countries) {
        if(country.second->getContinentName() == continent) {
            if(country.second->getOwner()->getPlayerId() != this->id) {
                countries.erase(country.second->getName());
            } else {
                theCountries.push_back(country.second);
            }
        }
    }
    return theCountries;
}



bool Player::controlsContinent(string name, GameMap *gameMap) {
    return getCountriesByContinent(name).size() == gameMap->getAllByContinent(name).size();
}


void Player::notifyObservers(){
    State newState = State(MOVE_COUNTRY);
    for(auto observer : observers) {
        observer->update(newState);
    }
};

void printStrategy(Strategy* strategy){
    switch(strategy->getType()){
        case 0:
            cout << "Human";
            break;
            
        case 1:
            cout << "Aggresive";
            break;
            
        case 2:
            cout << "Benevolent";
            break;
            
        case 3:
            cout << "Random";
            break;

        case 4:
            cout << "Cheater";
            break;
    }
};
