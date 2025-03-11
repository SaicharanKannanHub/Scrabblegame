#include <exception>

#include "PlayerHand.h"
#include "TilesBag.h"
#include "LinkedList.h"
#include "Utils.h"
#include "Tile.h"

PlayerHand::PlayerHand(TilesBag* tileBag) {
    this->tilesBag = tileBag;
    playerHandList = new LinkedList();
    size = 0;
}


PlayerHand::~PlayerHand() {
}

void PlayerHand::fillPlayerHand() {
    for(int i = 0; i < MAX_TILES_IN_HAND; i++ ) {
        addTile();
    }
}

Tile* PlayerHand::drawTile(char letter) {
    bool tileFound = false;
    Tile* tileToReturn = nullptr;
    
    int count = 0;
    while(!tileFound && count < playerHandList->size()) {
        if(playerHandList->get(count)->getLetter() == letter) {
            tileFound = true;
            
            Tile* tempTile = playerHandList->get(count);

            // Creates a new tile and allocates the value of tempTile
            tileToReturn = new Tile(tempTile->getLetter(), tempTile->getValue());

            // Removes tile from list
            playerHandList->remove(count);
            
            size--;
        }
        count++;
    }
    return tileToReturn;
}

bool PlayerHand::replaceTile(char letter) {
    bool tileFound = false;

    int count = 0;
    while(!tileFound && count < MAX_TILES_IN_HAND) {
        if(playerHandList->get(count)->getLetter() == letter) {
            tileFound = true;

            Tile* tempTile = playerHandList->get(count);

            // Adds tile to back of bag
            tilesBag->addTile(tempTile);    

            // Adds tile to back of hand from bag
            playerHandList->addBack(tilesBag->drawTile());
        }
    }
    return tileFound;
}


void PlayerHand::addTile() {
    
    if(playerHandList->size() <= MAX_TILES_IN_HAND) {
        playerHandList->addBack(tilesBag->drawTile());
        size++;
    }
    else {
        std::cout << "Your already have " << MAX_TILES_IN_HAND << "in hand." << std::endl;
    }
}

void PlayerHand::addTile(Tile* tile) {
    if(playerHandList->size() <= MAX_TILES_IN_HAND) {
        playerHandList->addBack(tile);
        size++;
    }
    else {
        std::cout << "Your already have " << MAX_TILES_IN_HAND << "in hand." << std::endl;
    }
}

void PlayerHand::printHand() {
    std::cout << "Your hand is: " << std::endl;

    // Loops through whole list 
    for(int i = 0; i < playerHandList->size(); i++) {
       
        // Checks if its not the last tile in the list  
        if(i != (playerHandList->size() - 1)) {
            std::cout << playerHandList->get(i)->getLetter() << "-"
            << playerHandList->get(i)->getValue() << ", ";
        } else {
                 std::cout << playerHandList->get(i)->getLetter() << "-"
            << playerHandList->get(i)->getValue() << std::endl;
        }
    }
}

Tile* PlayerHand::get(unsigned int index) {
    Tile* tile = nullptr;
    if(index < size) {
       tile =  playerHandList->get(index);
    } else {
        throw std::runtime_error("Index Out of bounds");
    }
    return tile;
}


unsigned int PlayerHand::getSize() const {
    return size;
}
