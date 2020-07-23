//
// Created by netanel on 25/05/2020.
//

#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#inclde "Board.hpp"

#include <vector>
#include <math.h>
using  namespace std;

namespace WarGame {
    void ParamedicCommander::Fight(vector<vector<Soldier *>> &board,pair<int, int> location) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->num_player ==this->num_player) { // if there is a soldier here and if soldier is belong to me
                    if (dynamic_cast<Paramedic *>(board[i][j])) {
                        pair<int, int> loc = {i, j};
                        board[i][j]->Paramedic::Fight(board, make_pair(i, j));
                    }
                }
            }
        }
    }
}
