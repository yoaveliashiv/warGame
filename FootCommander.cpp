//
// Created by netanel & Or on 25/05/2020.
//
//
#include <cmath>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "FootSoldier.cpp"
#include "Soldier.hpp"
#include "Soldier.cpp"
#include "Sniper.cpp"
#include "Board.hpp"
#include "Board.cpp"
#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <zconf.h>
namespace WarGame {
    void FootCommander::fight(vector <vector<Soldier *>> &board, std::pair<int, int> location) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->num_player == this->num_player) { // if soldier belong to me
                    if (dynamic_cast<FootSoldier *>(board[i][j])) {
                        std::pair<int, int> loc = {i, j};
                        board[i][j]->FootSoldier::Fight(board, make_pair(i, j));
                    }
                }
            }
        }
    }
}