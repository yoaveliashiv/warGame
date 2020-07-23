//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_FOOTSOLDIER_HPP
#define WARGAME_FOOTSOLDIER_HPP

#include "Soldier.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

using  namespace std;
class FootSoldier:public Soldier{//יורש מסולדר
public:
    FootSoldier(int num_p):Soldier(100,10,num_p,100){}//בנאי
     void Fight(vector<vector<Soldier*>> &board, pair<int,int> location)  override ;//דריסה
};

#endif //WARGAME_FOOTSOLDIER_HPP
