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
    m_Damage = Speed;
}

void Archer::reset() {
    Fighter::reset();
    m_CurrentSpeed = m_Speed;
}

//----------------------------------------------------------------------------------
//Archer-specific battle functions
int Archer::getDamage() {
    return m_Damage;
}

bool Archer::useAbility() {
    m_CurrentSpeed++;
    return true;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------








