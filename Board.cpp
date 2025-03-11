#include "Board.h"


Board::Board(){
    boardVec.resize(MAX_ROW,std::vector<std::string> (MAX_COL, "   "));
}

void Board::displayBoard(){

    std::cout << BOARD_HEAD << std::endl;
    std::cout << BOARD_HEAD_BREAK << std::endl;

    for(int i = 0; i < MAX_ROW; i++) { 

        std::cout << ALPHABETS[i];
        for(int j = 0; j < MAX_COL; j++)
        {
            std::cout << "|" << boardVec[i][j];
        }
        std::cout<< "|" <<std::endl;
    }

}

void Board::setTileOnBoard(char row,int col, char value){
    int counter = 0;
    // std::string test = row;
    for(int i = 0; i < MAX_ROW; i++) {
        if(ALPHABETS[i] == row){
            counter = i;
        }
    }
    std::string valueToAdd = " ";
    valueToAdd.push_back(value);
    valueToAdd += " ";
    boardVec[counter][col] = valueToAdd;
}

std::string Board::getLetterOnBoard(char row, int col) {

    int counter = 0;
    for(int i = 0; i < MAX_ROW; i++) {
        if(ALPHABETS[i] == row){
            counter = i;
        }
    }
    std::string letter = boardVec[counter][col];

    return letter;
}


twoDVector Board::getStoredBoard() {
    return boardVec;
}