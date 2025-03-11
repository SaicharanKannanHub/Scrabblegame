#include "Tile.h"

// Empty... for now?

Tile::Tile(Letter letter,Value value) {
    this->letter= letter;
    this->value= value;
    
}

Letter Tile::getLetter(){
    return letter;
}

Value Tile::getValue(){
    return value;
}