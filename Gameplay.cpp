#include <fstream>
#include <exception>
#include <sstream>
#include <string>
#include <vector>

#include "Gameplay.h"
#include "Board.h"
#include "Player.h"
#include "PlayerHand.h"
#include "TilesBag.h"
#include "Tile.h"
#include "Utils.h"

Gameplay::Gameplay(Player* player1, Player* player2, TilesBag* tilesBag) {
    this->tilebag = tilesBag;
    p1 = player1;
    p2 = player2;
    currentPlayer = p1;
    board = new Board();
}

void Gameplay::startGame(){

    while(!exit) {
        if(currentPlayer == p1) {
            player1Game();
        }
        if(!exit) {
            if(currentPlayer == p2) {
                player2Game();
            }
        }
    }
}

void Gameplay::player1Game() {
    printDetails();
    bool p1exit = false;
    while(!p1exit) {
        std::vector<std::string> userInput = getSplitedInputAsVector();

        if(userInput[0] == "place" && userInput[2] == "at" && userInput.size() == 4) {
            // Checks if 2 string length is 1 - which means its char
            if(userInput[1].length() == 1) {
                
                // Checks is position to place letter is correct
                std::string vecToStringLoc = userInput[3];
                char row = vecToStringLoc[0];

                // If row is 2 no or 1
                int col = -1;
                if(userInput[3].length() == 3) {
                    
                    std::string temp = "";
                    int tempInt1 = vecToStringLoc[1] - '0';
                    int tempInt2 = vecToStringLoc[2] - '0';
                    temp += std::to_string(tempInt1);
                    temp += std::to_string(tempInt2);
                    col = std::stoi(temp);
                } else {
                    col = vecToStringLoc[1] - '0';
                }

                bool isLetterLocValid = validLetterLocation(row);
                if(userInput[3].length() <= 3 && userInput[3].length() >= 2 &&
                 isLetterLocValid == true && col >= 0 && col < MAX_ROW) {

                    // Checks if board at loc is empty
                    if(board->getLetterOnBoard(row, col) == "   ") {
                        std::string vecToStringLetter =  userInput[1];
                        char letter = vecToStringLetter[0];

                        // Checks if tile exists in hand
                        Tile* tile = currentPlayer->getPlayerHand()->drawTile(letter);
                        if(tile != nullptr) {
                            board->setTileOnBoard(row, col, tile->getLetter());
                            currentPlayer->addScore(tile->getValue());
                            delete tile;
                        }
                        else { // Checks if tile exists in hand
                            std::cout << "Tile not found in your hand" << std::endl;
                        }
                    } else { // Checks if board at loc is empty
                         std::cout << "Board is not empty at this location" << std::endl;
                    }
                } else {// Checks is position to place letter is correct
                    std::cout << "'" << userInput[3] << "' is not a valid location" << std::endl;
                }
            } else { // Checks if 2 string length is 1 - which means its char
                std::cout << "'" << userInput[1] << "' is not a letter valid letter" << std::endl;
            }
        } 
        else if (userInput[0] == "place" && userInput[1] == "Done" && userInput.size() == 2) {
            std::cout << std::endl;
            currentPlayer = p2;
            p1exit = true;
        }
        else if (userInput[0] == "replace" && userInput.size() == 2) {
            // Checks if 2 string length is 1 - which means its char
            if(userInput[1].length() == 1) {
                std::string vecToStringLetter =  userInput[1];
                char letter = vecToStringLetter[0];
                
                bool replaced = currentPlayer->getPlayerHand()->replaceTile(letter);
                // Checks if tile is replaced
                if(replaced) {
                    std::cout << std::endl;
                    currentPlayer = p2;
                    p1exit = true;
                }
                else {
                    std::cout << "Tile not found in your hand" << std::endl;
                }
             }
            else {
                std::cout << "'" << userInput[1] << "' is not a letter valid letter" << std::endl;
            }
            
        }
        else if (userInput[0] == "pass" && userInput.size() == 1) {
            std::cout << std::endl;
            currentPlayer = p2;
            p1exit = true;
        }
        else if (userInput[0] == "save" && userInput.size() == 2) {
            bool saved = saveGame(userInput[1]);
            if(saved) {
                p1exit = true;
                exit = true;
            }
            else {
                std::cout << "Unable to save the game" << std::endl;
            }
        }
        else {
            std::cout << "Please enter a valid command" << std::endl;
        }

    }

}

void Gameplay::player2Game() {
    printDetails();
    bool p2exit = false;
    while(!p2exit) {
        std::vector<std::string> userInput = getSplitedInputAsVector();

        if(userInput[0] == "place" && userInput[2] == "at" && userInput.size() == 4) {
            // Checks if 2 string length is 1 - which means its char
            if(userInput[1].length() == 1) {
                
                // Checks is position to place letter is correct
                std::string vecToStringLoc = userInput[3];
                char row = vecToStringLoc[0];

                // If row is 2 no or 1
                int col = -1;
                if(vecToStringLoc.length() == 3) {
                    
                    std::string temp = "";
                    int tempInt1 = vecToStringLoc[1] - '0';
                    int tempInt2 = vecToStringLoc[2] - '0';
                    temp += std::to_string(tempInt1);
                    temp += std::to_string(tempInt2);
                    col = std::stoi(temp);
                } else {
                    col = vecToStringLoc[1] - '0';
                }

                bool isLetterLocValid = validLetterLocation(row);
                if(userInput[3].length() <= 3 && userInput[3].length() >= 2 &&
                 isLetterLocValid == true && col >= 0 && col < MAX_ROW) {

                    // Checks if board at loc is empty
                    if(board->getLetterOnBoard(row, col) == "   ") {
                        std::string vecToStringLetter =  userInput[1];
                        char letter = vecToStringLetter[0];

                        // Checks if tile exists in hand
                        Tile* tile = currentPlayer->getPlayerHand()->drawTile(letter);
                        if(tile != nullptr) {
                            board->setTileOnBoard(row, col, tile->getLetter());
                            currentPlayer->addScore(tile->getValue());
                            delete tile;
                        }
                        else { // Checks if tile exists in hand
                            std::cout << "Tile not found in your hand" << std::endl;
                        }
                    } else { // Checks if board at loc is empty
                         std::cout << "Board is not empty at this location" << std::endl;
                    }
                } else {// Checks is position to place letter is correct
                    std::cout << "'" << userInput[3] << "' is not a valid location" << std::endl;
                }
            } else { // Checks if 2 string length is 1 - which means its char
                std::cout << "'" << userInput[1] << "' is not a letter valid letter" << std::endl;
            }
        } 
        else if (userInput[0] == "place" && userInput[1] == "Done" && userInput.size() == 2) {
            std::cout << std::endl;
            currentPlayer = p1;
            p2exit = true;
        }
        else if (userInput[0] == "replace" && userInput.size() == 2) {
            // Checks if 2 string length is 1 - which means its char
            if(userInput[1].length() == 1) {
                std::string vecToStringLetter =  userInput[1];
                char letter = vecToStringLetter[0];
                
                bool replaced = currentPlayer->getPlayerHand()->replaceTile(letter);
                // Checks if tile is replaced
                if(replaced) {
                    std::cout << std::endl;
                    currentPlayer = p1;
                    p2exit = true;
                }
                else {
                    std::cout << "Tile not found in your hand" << std::endl;
                }
             }
            else {
                std::cout << "'" << userInput[1] << "' is not a letter valid letter" << std::endl;
            }
            
        }
        else if (userInput[0] == "pass" && userInput.size() == 1) {
            std::cout << std::endl;
            currentPlayer = p1;
            p2exit = true;
        }
        else if (userInput[0] == "save" && userInput.size() == 2) {
            bool saved = saveGame(userInput[1]);
            if(saved) {
                p2exit = true;
                exit = true;
            }
            else {
                std::cout << "Unable to save the game" << std::endl;
            }
        }
        else {
            std::cout << "Please enter a valid command" << std::endl;
        }

    }

}

void Gameplay::printDetails() {
    std::cout << currentPlayer->getName() << ", its your turn to play" << std::endl;
    std::cout << "Score for "<< p1->getName()<<": "<< p1->getScore() << std::endl;
    std::cout << "Score for "<< p2->getName()<<": "<< p2->getScore() << std::endl;
    
    board->displayBoard();
    std::cout << std::endl;
    currentPlayer->getPlayerHand()->printHand();
    std::cout << std::endl;
}

std::vector<std::string> Gameplay::getSplitedInputAsVector() {
    std::vector<std::string> inputVector;
    std::string input = "";
    std::cout << USER_INPUT_SIGN;

    std::cin >> input;
    inputVector.push_back(input);

    std::getline(std::cin, input);

    std::stringstream ss(input);
    
    int count = 0;
    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ' ');
        if(count != 0) {
            inputVector.push_back(substr);
        }
        count++;
    }

    return inputVector;
}

bool Gameplay::validLetterLocation(char letter) {
    bool isValid = false; 

    int i = 0;
    while(i < MAX_ROW && !isValid) {
        // std::cout << alpha[i];
        if(letter == ALPHABETS[i]) {
            isValid = true;
        }
        i++;
    }
    return isValid;
}

Board* Gameplay::getBoard() {
    return board;
}

void Gameplay::setCurrentPlayer(Player* currentPlayer) {
    this->currentPlayer = currentPlayer;
}


bool Gameplay::saveGame(std::string filePath) {
    bool success = false;
    filePath += ".txt";

    try {
        
        std::ofstream file(filePath);

        // Player 1
        file << p1->getName();
        file << std::endl;
        file << p1->getScore();
        file << std::endl;

        for(int i = 0; i < p1->getPlayerHand()->getSize(); i++) {
            try {
                if(i < (p1->getPlayerHand()->getSize() - 1)) {
                    file << p1->getPlayerHand()->get(i)->getLetter() << "-" << 
                    p1->getPlayerHand()->get(i)->getValue() << ",";
                }
                else {
                    file << p1->getPlayerHand()->get(i)->getLetter() << "-" << 
                    p1->getPlayerHand()->get(i)->getValue();
                    file << std::endl;

                }
            } catch (std::runtime_error e) { 
                std::cout << e.what() << std::endl;
            }
        }

        // Player 2
        file << p2->getName();
        file << std::endl;
        file << p2->getScore();
        file << std::endl;
        
        for(int i = 0; i < p2->getPlayerHand()->getSize(); i++) {
            try {
                if(i < (p2->getPlayerHand()->getSize() - 1)) {
                    file << p2->getPlayerHand()->get(i)->getLetter() << "-" << 
                    p2->getPlayerHand()->get(i)->getValue() << ",";
                }
                else {
                    file << p2->getPlayerHand()->get(i)->getLetter() << "-" << 
                    p2->getPlayerHand()->get(i)->getValue();
                    file << std::endl;
                }
            } catch (std::runtime_error e) { 
                std::cout << e.what() << std::endl;
            }
        }

        // Board
        twoDVector twoDVector = board->getStoredBoard();
        for(int i = 0; i < MAX_ROW; i++) {
            for(int j = 0; j < MAX_COL; j++) {
                if(j != (MAX_COL - 1)) {
                    if(twoDVector[i][j] != "   ") {
                        file << twoDVector[i][j] << ",";
                    } else {
                        file << "   ,";
                    }
                } else {
                    if(twoDVector[i][j] != "   ") {
                        file << twoDVector[i][j];
                    } else {
                        file << "   ";
                    }
                }
            }
            file << std::endl;
        }
        

        // TilesBag
        for(int i = 0; i < tilebag->getSize(); i++) {
            try {
                if(i <  (tilebag->getSize() - 1)) {
                    file <<tilebag->get(i)->getLetter() << "-" << 
                    tilebag->get(i)->getValue() << ",";
                }
                else {
                        file << tilebag->get(i)->getLetter() << "-" << 
                        tilebag->get(i)->getValue();
                        file << std::endl;
                }
            } catch (std::runtime_error e) { 
                std::cout << e.what() << std::endl;
            }
        }

        // Current Player
        file << currentPlayer->getName();

        // Closes open file
        file.close();
        success = true;

    } catch (std::exception) {
        std::cout << "File at: " << filePath << " Not Found" << std::endl;
    }
    return success;
}

