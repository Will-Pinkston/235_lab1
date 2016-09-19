//
//  Cleric.cpp
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#include <stdio.h>
#include "Cleric.h"

Cleric::Cleric(string name, int MaximumHP, int Strength,
               int Speed, int Magic) : Fighter (name, MaximumHP, Strength, Speed, Magic) {
    m_Damage = Magic;
    m_MaxMana = 5 * Magic;
    m_Mana = m_MaxMana;
}

void Cleric::reset() {
    Fighter::reset();
    m_Mana = m_MaxMana;
}

//----------------------------------------------------------------------------------
//Cleric-specific battle functions
int Cleric::getDamage() {
    return m_Damage;
}

void Cleric::regenerate() {
    Fighter::regenerate();

    int Regen = m_Magic / 5;
    if (Regen == 0) {
        Regen = 1;
    }
    int testRegen = m_Mana;
    testRegen += Regen;
    if (testRegen > m_MaxMana) {
        m_Mana = m_MaxMana;
    } else {
        m_Mana += Regen;
    }
}

bool Cleric::useAbility() {
    if (m_Mana < CLERIC_ABILITY_COST) {
        return false;
    } else {
        int heal = m_Magic;
        heal /= 3;
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
        m_Mana -= CLERIC_ABILITY_COST;
        return true;
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------




