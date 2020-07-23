//
// Created by netanel & Or on 25/05/2020.
//
#include "FootSoldier.hpp"
//#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <zconf.h>

//get the board and location of the soldier that attack soldier that near to him
void FootSoldier::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    int inf = 1000000000;
    int dist = 0;
    int index_i;
    int index_j;
    Soldier *attack= board[location.first][location.second];
    int damage_attack=attack->get_damage();
    int team = attack->get_num_player();
    pair<int, int> target;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(board[i][j]!=nullptr && board[i][j]->get_num_player()!=team){
                 dist = sqrt(pow((location.first - i), 2) + pow((location.second - j), 2));
                if (dist < inf){
                    inf=dist;
                    index_i=i;
                    index_j=j;
                }
            }

        }
    }

    board[index_i][index_j]->set_health(board[index_i][index_j]->get_health()-damege_attack);


    if (board[index_i][index_j]->get_health()<=0){
        delete board[index_i][index_j];
        board[index_i][index_j]= nullptr;
    }

}





