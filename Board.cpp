#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
using namespace std;
#include <iostream>
namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {//  השמה ברפרנס
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {//לקבל למשתנה בלי יכולת לשנות את הערכים הפנימיים שלו
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
        Soldier *src = board[source.first][source.second];
        if (src == nullptr) {//אין חייל במיקום
            throw invalid_argument("No player on source");
        }
        if (src->get_num_player() != player_number) {//אם החייל במיקום לא שייך לקבוצה להפונקצייה קיבלה
            throw invalid_argument("Wrong player number");
        }
        // Up, Down, Right, Left
        pair<int, int> dest;//שדה
        switch (direction) {//לזוז לפי האינמים שמאלה ימינה וכו
            case Up :
                dest = make_pair(source.first + 1, source.second);
                break;
            case Down :
                dest = make_pair(source.first - 1, source.second);
                break;
            case Right :
                dest = make_pair(source.first, source.second + 1);
                break;
            case Left :
                dest = make_pair(source.first, source.second - 1);
                break;

        }
        if (dest.first < 0 || dest.second < 0 || dest.first >= board.size() ||
            dest.second >= board[dest.first].size()) {
            throw invalid_argument("out of bounds");
        }
        if (board[dest.first][dest.second] != nullptr) {
            throw invalid_argument("trying to move to a allocated space");
        }
        board[dest.first][dest.second] = src;//הקידום בפועל
        board[source.first][source.second] = nullptr;//מוחק מהמיקום הקודם
        src->Fight(board, dest);//התקפה
    }

    void Board::print_board() {
        for (int i = 0; i < this->board.size(); i++) {
            for (int j = 0; j < this->board[0].size(); j++) {
                if (this->board[i][j])  //!=NULL

                    cout <<"   "<<this->board[i][j]->num_player <<" "<< this->board[i][j]->health<<"  " ;
                else
                    cout << "  ------  " ;

            }
            cout<<"     "<<endl;

        }
        cout<<"   "<<endl;
        cout<<"   "<<endl;

        cout<<"   "<<endl;
        cout<<"   "<<endl;

    }

    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                Soldier *s = board[i][j];
                if (s != nullptr) {
                    if (s->get_num_player() == player_number) {
                        return true;
                    }

                }
            }
        }
        return false;
    }

}
