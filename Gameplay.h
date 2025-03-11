#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>


class Player;
class Board;
class PlayerHand;
class TilesBag;

class Gameplay {
    public:

        Gameplay(Player* player1, Player* player2, TilesBag* tilesBag);
        
        /**
         * Start playing game
         */
        void startGame();

        /**
         * Prints board and player info
         */
        void printDetails();

        /**
         * Takes user input splits it up and returns vector
         */
        std::vector<std::string> getSplitedInputAsVector();

        /**
         * checks is char is between A-O
         */ 
        bool validLetterLocation(char letter);

        /**
         * Returns current board
         */
        Board* getBoard();

        /**
         * Sets current player
         */
        void setCurrentPlayer(Player* currentPlayer);

        /**
         * Saves current game to a file
         * returns if true if save was success
         */
        bool saveGame(std::string filePath);

    private:
        Player* p1;
        Player* p2;
        Player* currentPlayer;
        Board* board;
        TilesBag* tilebag;
        bool exit = false;

        /**
         * Takes player 1 inputs 
         */
        void player1Game();

        /**
         * Takes player 2 inputs 
         */
        void player2Game();
};



#endif //GAMEPLAY_H