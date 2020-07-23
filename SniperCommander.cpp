//
// Created by netanel on 25/05/2020.
//

#include "SniperCommander.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <vector>
#include <math.h>
#include "Sniper.hpp"

void SniperCommander::Fight(std::vector<std::vector<Soldier*>> &board, pair<int, int> location) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j]!= nullptr &&board[i][j]->num_player== this->num_player)
                { // if soldier belong to me
                    if (dynamic_cast<Sniper *>(board[i][j]))
                    {
                        pair<int, int> loc = {i, j};
                        board[i][j]->Sniper::Fight(board, loc);
                    }
                }
            }
        }
    }
