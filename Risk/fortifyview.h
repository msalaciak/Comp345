//
//  fortifyview.hpp
//  Risk
//
//  Created by Allan Pichardo on 10/20/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "player.h"
#include "country.h"
#include <vector>

using namespace std;

class FortifyView {
    
private:
    
public:
    Country* promptCountrySelect(string prompt, vector<Country*> countries);
    void presentFortify();
    Country* promptUserForOrigin(vector<Country*> countries);
    Country* promptUserForDestination(vector<Country*> countries);
    int promptUserForAmountOfArmies(Country* fromCountry);
};

