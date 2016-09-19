//
//  Fighter.h
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#ifndef Fighter_h
#define Fighter_h

#include "FighterInterface.h"

using namespace std;

class Fighter : public FighterInterface {
protected:
    string m_name;
    int m_Strength;
    int m_Speed;
    int m_Magic;
    int m_MaximumHP;
    int m_CurrentHP;

public:
    Fighter(string name, int mMaximumHP, int Strength,
            int Speed, int Magic);
    
    string getName();
    int getMaximumHP();
    int getCurrentHP();
    int getStrength();
    int getSpeed();
    int getMagic();
    
    virtual int getDamage() = 0;
    
    void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility() = 0;
};


#endif /* Fighter_h */
