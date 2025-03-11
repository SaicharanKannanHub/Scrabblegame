#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class PlayerHand;
class TilesBag;

class Player{
    public:
        Player(std::string name, TilesBag* tilsBag);

        /**
         * Returns current score of the player 
         */
        int getScore();

        /**
         * Returs name of the player
         */ 
        std::string getName();

        /**
         * sets score of the player 
         */
        void addScore(int score);

        /**
         * Returns player hand 
         */
        PlayerHand* getPlayerHand();

    private:
        std::string name;
        int score;
        PlayerHand* playerhand; 
};

#endif //PLAYER_H