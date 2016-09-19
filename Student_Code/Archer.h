//
//  Archer.h
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#ifndef Archer_h
#define Archer_h

#include <string>
#include "Fighter.h"

using namespace std;

class Archer : public Fighter {
protected:
    int m_Damage;
    int m_Speed;
    int m_CurrentSpeed;
    
public:
    Archer(string name, int mMaximumHP, int Strength,
          int Speed, int Magic);
    
    void reset();
    int getDamage();
    bool useAbility();
};

#endif /* Archer_h */
