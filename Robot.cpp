//
//  Robot.cpp
//
//
//  Created by William Pinkston on 9/14/16.
//
//

#include <stdio.h>
#include "Robot.h"
#include <math.h>

Robot::Robot(string name, int MaximumHP, int Strength,
             int Speed, int Magic) : Fighter(name, MaximumHP, Strength, Speed, Magic) {
    m_Damage = Strength;
    m_Energy = 2 * Magic;
    m_MaxEnergy = m_Energy;
    m_BonusDamage = 0;
}

void Robot::reset() {
    Fighter::reset();
    m_Energy = m_MaxEnergy;
    m_BonusDamage = 0;
}

//----------------------------------------------------------------------------------
//Robot-specific battle functions
int Robot::getDamage() {
    int dmg = m_Damage + m_BonusDamage;
    return dmg;
}

bool Robot::useAbility() {
    m_BonusDamage = 0;
    if (m_Energy < ROBOT_ABILITY_COST) {
        return false;
    } else {
        double current_energy = m_Energy;
        double max_energy = m_MaxEnergy;
        double str = m_Strength;
        double bonus = (str * pow((current_energy / max_energy), 4));
        m_BonusDamage = bonus;
        m_Energy -= ROBOT_ABILITY_COST;
        return true;
    }//DOUBLE CHECK THE DOUBLE AND INT ARITHMATIC
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

