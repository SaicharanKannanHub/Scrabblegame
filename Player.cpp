#include "Player.h"
#include "PlayerHand.h"
#include "TilesBag.h"

Player::Player(std::string name, TilesBag* tilesBag) {
    this->name = name;
    playerhand = new PlayerHand(tilesBag); 
    score = 0;
}

int Player::getScore(){
    return score;
}

std::string Player::getName(){
    return name;
}

PlayerHand* Player::getPlayerHand() {
    return playerhand;
}

void Player::addScore(int score){
    this->score += score;
}
