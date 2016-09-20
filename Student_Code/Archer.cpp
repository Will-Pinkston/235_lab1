//
//  Archer.cpp
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#include <stdio.h>
#include "Archer.h"

Archer::Archer(string name, int MaximumHP, int Strength,
               int Speed, int Magic) : Fighter (name, MaximumHP, Strength, Speed, Magic) {
    m_Speed = Speed;
    m_CurrentSpeed = Speed;
    m_Damage = m_CurrentSpeed;
}

void Archer::reset() {
    Fighter::reset();
    m_CurrentSpeed = m_Speed;
    m_Damage = m_CurrentSpeed;
}

//----------------------------------------------------------------------------------
//Archer-specific battle functions
int Archer::getDamage() {
    return m_Damage;
}

bool Archer::useAbility() {
    m_CurrentSpeed++;
    m_Damage = m_CurrentSpeed;
    return true;
}

int Archer::getSpeed() {
    return m_CurrentSpeed;
}

void Archer::takeDamage(int damage) {
    int evadeRedux = m_CurrentSpeed / 4;
    damage -= evadeRedux;
    if (damage <= 0) {
        damage = 1;
    }
    m_CurrentHP -= damage;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------








