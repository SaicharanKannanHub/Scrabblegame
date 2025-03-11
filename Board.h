#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Utils.h"


class Board {
    public:
        Board();
        // ~Board();

        void displayBoard();

        // int buildBoard();

        // void setTileOnBoard(char row, int col, std::string value);
        void setTileOnBoard(char row, int col, char value);
        

        /**
         * Returns the letter on specific location
         */
        std::string getLetterOnBoard(char row, int col);

        /**
         * Returns 2D vector storing board data
         */
        twoDVector getStoredBoard();

    private:
        twoDVector boardVec; 
};


#endif //BOARD_H