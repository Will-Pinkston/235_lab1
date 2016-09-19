//
//  Robot.h
//  235_lab_1_test
//
//  Created by William Pinkston on 9/14/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#ifndef Robot_h
#define Robot_h

#include <string>
#include "Fighter.h"

using namespace std;

class Robot : public Fighter {
protected:
    int m_Damage;
    int m_Energy;
    int m_MaxEnergy;
    int m_BonusDamage;
    
public:
    Robot(string name, int mMaximumHP, int Strength,
          int Speed, int Magic);
    
    void reset();
    int getDamage();
    bool useAbility();
};

#endif /* Robot_h */
