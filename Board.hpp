/**
 * Header file for the board of the war game.
 * 
 * You can copy this file to a new file called Board.hpp, and extend it as you like.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */
#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

//#include "DemoGame.hpp"


namespace WarGame {

class Board {
private:
  std::vector<std::vector<Soldier*>> board;

public:
    enum MoveDIR { Up, Down, Right, Left };

    Board(uint numRows, uint numCols) :
        board(numRows, std::vector<Soldier*>(numCols, nullptr)){}

        // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int,int> location);//השמה

    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int,int> location) const;//לקבל בלי אופציה לשנות את החייל את הערכים חיים וכו

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument".
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const;//נשאר  חיילים וקבוע שאי אפשר לשנות ואז לרמא
    void print_board();
//    ~Board()
//    {
//      for (auto row: board) {
//		 		for (auto soldier: row) {
//		 			if (soldier)
//		 				delete soldier;
//		 		}
//		 	}
//      board.clear();
//    }

};

}
