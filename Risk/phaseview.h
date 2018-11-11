//
//  phaseview.h
//  Risk
//
//  Created by Allan Pichardo on 11/11/18.
//  Copyright © 2018 comp345. All rights reserved.
//

#pragma once

#include "observer.h"

class PhaseView : public Observer {
public:
    void print();
    void update(State& state);
};
