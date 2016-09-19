//
//  Cleric.h
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#ifndef Cleric_h
#define Cleric_h

#include <string>
#include "Fighter.h"

using namespace std;

class Cleric : public Fighter {
protected:
    int m_Damage;
    int m_MaxMana;
    int m_Mana;
    
public:
    Cleric(string name, int mMaximumHP, int Strength,
          int Speed, int Magic);
    
    void reset();
    int getDamage();
    void regenerate();
    bool useAbility();
};

#endif /* Cleric_h */
