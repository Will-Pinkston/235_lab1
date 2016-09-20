//
//  Fighter.cpp
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#include <stdio.h>
#include "Fighter.h"

Fighter::Fighter(string name, int MaximumHP, int Strength,
                 int Speed, int Magic) {
    m_name = name;
    m_MaximumHP = MaximumHP;
    m_CurrentHP = MaximumHP;
    m_Strength = Strength;
    m_Speed = Speed;
    m_Magic = Magic;
}
//----------------------------------------------------------------------------------
//Get functions
string Fighter::getName(){
    return m_name;
}
int Fighter::getMaximumHP() {
    return m_MaximumHP;
}
int Fighter::getCurrentHP() {
    return m_CurrentHP;
}
int Fighter::getStrength() {
    return m_Strength;
}
int Fighter::getSpeed() {
    return m_Speed;
}
int Fighter::getMagic() {
    return m_Magic;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//Battle commands
void Fighter::reset() {
    m_CurrentHP = m_MaximumHP;
}

void Fighter::takeDamage(int damage) {
    int evadeRedux = m_Speed / 4;
    damage -= evadeRedux;
    if (damage <= 0) {
        damage = 1;
    }
    m_CurrentHP -= damage;
}
void Fighter::regenerate() {
    int heal = m_Strength / 6;
    if (heal == 0) {
        heal = 1;
    }
    int testHeal = m_CurrentHP;
    testHeal += heal;
    if (testHeal > m_MaximumHP) {
        m_CurrentHP = m_MaximumHP;
    } else {
        m_CurrentHP += heal;
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


