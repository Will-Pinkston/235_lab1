//
//  Arena.h
//  
//
//  Created by William Pinkston on 9/13/16.
//
//

#ifndef Arena_h
#define Arena_h
#include <vector>
#include <string>
#include "FighterInterface.h"
#include "Fighter.h"
#include "ArenaInterface.h"

class Arena : public ArenaInterface {
private:
    vector<FighterInterface*> m_Roster;//list of all the fighters currently in the arena
    
public:
    Arena();
    
    bool addFighter(string info);
    bool removeFighter(string name);
    FighterInterface* getFighter(string name);
    int getSize();
};

#endif /* Arena_h */
