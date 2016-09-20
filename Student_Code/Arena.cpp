//
//  arena.cpp
//  
//
//  Created by William Pinkston on 9/13/16.
//
//

#include <stdio.h>
#include <sstream>
#include "Arena.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"

Arena::Arena() {}

//----------------------------------------------------------------------------------
//Utility functions
bool checkName (string name, vector<FighterInterface*> m_Roster) {
    //add some code to check the given name against the names in the arena
    if (name == "") {
        return false;
    } else {
        int size = (int)m_Roster.size();
        for (int i = 0; i < size; i++) {
            string find_name = m_Roster[i]->getName();
            if (find_name == name) {
                return false;
            }
        }
        return true;
    }
}
int checkType (string type) {
    if (type == "R") {          //Robot
        return 1;
    } else if (type == "A") {   //Archer
        return 2;
    } else if (type == "C") {   //Cleric
        return 3;
    } else {                    //invalid type
        return -1;
    }
}
bool checkValue (int value) {
    if (value > 0) {
        return true;
    } else {
        return false;
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//Add a new fighter into the arena
bool Arena::addFighter(string info) {
    cout << "Arena::addFighter" << endl;
//    parse out the info string into the given format
    stringstream ss;
    ss << info;
//    member variables for the fighter
    string name = "";
//    start testing each part of the input
//    filter name
    ss >> name;
    if (checkName(name, m_Roster)) {
        string type = "x";
//        filter type
        ss >> type;
        int typetest = checkType(type);
        if (typetest > -1) {
            int maxHP = -1;
//            filter maxHP
            ss >> maxHP;
            if (checkValue(maxHP)) {
                int strength = -1;
//                filter strength
                ss >> strength;
                if (checkValue(strength)) {
                    int speed = -1;
//                    filter speed
                    ss >> speed;
                    if (checkValue(speed)) {
                        int magic = -1;
//                        filter magic
                        ss >> magic;
                        if (checkValue(magic)) {
                            string overflow_check = "fail";
                            ss >> overflow_check;
                            if (overflow_check == "fail") {
//                                input verified
//                                create new fighter
                                switch(typetest) {
                                    case 1: { //robot
                                        FighterInterface* addRobot = new Robot(name, maxHP, strength,
                                                  speed, magic);
                                        m_Roster.push_back(addRobot);
                                        return true;
                                    }
                                        break;
                                    case 2: { //archer
                                        FighterInterface* addArcher = new Archer(name, maxHP, strength,
                                                                                 speed, magic);
                                        m_Roster.push_back(addArcher);
                                        return true;
                                    }
                                        break;
                                    case 3: { //cleric
                                        FighterInterface* addCleric = new Cleric(name, maxHP, strength,
                                                                                 speed, magic);
                                        m_Roster.push_back(addCleric);
                                        return true;
                                    }
                                        break;
                                    default:
                                        return false;
                                        break;
                                }
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//remove a fighter from the arena
bool Arena::removeFighter(string name) {
    cout << "Arena::removeFighter" << endl;
    if (checkName(name, m_Roster)) {
        cout << "remove fail" << endl;
        return false;
    } else {
        bool found = false;
        int i = 0;
        while(!found) {
            if (m_Roster[i]->getName() == name) {
                found = true;
            } else if (i < m_Roster.size()) {
                i++;
            }
        }
        int final_index = ((int)m_Roster.size()) - 1;
        m_Roster[i] = m_Roster[final_index];
        m_Roster.pop_back();
        return true;
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//Get a pointer to a fighter in the arena
FighterInterface* Arena::getFighter(string name) {
    cout << "Arena::getFighter" << endl;
    if(checkName(name, m_Roster)) {
        FighterInterface* nilIt = NULL;
        return nilIt;
    } else {
        bool found = false;
        int i = 0;
        while(!found) {
            if (m_Roster[i]->getName() == name) {
                found = true;
            } else if (i < m_Roster.size()) {
                i++;
            }
        }
        return m_Roster[i];
    }
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//Returns the number of fighters in the arena
int Arena::getSize() {
    cout << "Arena::getSize" << endl;
    return (int)m_Roster.size();
}
//----------------------------------------------------------------------------------






