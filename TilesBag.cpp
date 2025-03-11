#include <fstream>
#include <random>

#include "Utils.h"
#include "TilesBag.h"
#include "Tile.h"
#include "LinkedList.h"


TilesBag::TilesBag() {
    tileList = new LinkedList();
    size = 0;
}

TilesBag::TilesBag(const TilesBag& other) {
    tileList = new LinkedList(*other.tileList);
}

TilesBag::~TilesBag() {
    clearBag();
}

void TilesBag::fillBag() {
    loadFile();
    shuffleTiles();

    // Copy's all Vector elements to LinkedList
    // Fills the bag
    for(int i = 0; i < (int) tilesVector.size(); i++) {
        // tileList->addBack(tilesVector[i]);
        addTile(tilesVector[i]);
        // Sets vector to nullptr
        tilesVector[i] = nullptr;
    }
}

Tile* TilesBag::drawTile() {
    Tile* tile  = nullptr;
    
    // Checks if the list is not empty
    // This could also be implemeted by using tileList->size();
    try {
        // Creates a temp tile
        Tile* tempTile = tileList->getFront();

        // Creates a new tile and allocates the value of tempTile
        tile = new Tile(tempTile->getLetter(), tempTile->getValue());

        // Deletes drawnTile from list
        tileList->removeFront();
        
        size--;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return tile;
}

void TilesBag::addTile(Tile* tile) {
    tileList->addBack(tile);
    size++;
}

Tile* TilesBag::get(unsigned int index) {
    Tile* tile = nullptr;
    if(index < size) {
       tile =  tileList->get(index);
    } else {
        throw std::runtime_error("Index Out of bounds");
    }
    return tile;
}


unsigned int TilesBag::getSize() const {
    return size;
}


void TilesBag::clearBag() {
    // Removes everything from LinkedList
   for(int i = 0; i < tileList->size(); i++) {
       tileList->remove(i);
       size--;
   }
}

void TilesBag::loadFile() {

    // Opens the file
    try {
        std::ifstream file(SCRABBLE_TILES_FILE_NAME);

        if(file) {
            // Read the file
            char letter;
            int value;
            int numRead = 0;
            while(!file.eof() && numRead < MAX_TILES_QUANTITY) {

                file >> letter;
                file >> value;

                // Creates Temp tile 
                Tile* tempTile = new Tile(letter, value);
                // Adds temp tile to vector
                tilesVector.push_back(tempTile);

                numRead++;
            }

            // Closes the file
            file.close();
        } else {
            std::cout << "File: " << SCRABBLE_TILES_FILE_NAME << " Not Found" << std::endl; 
        }
        
    } catch (std::exception) {
        std::cout << "Error occured in File: " <<  SCRABBLE_TILES_FILE_NAME << std::endl; 
    }
}


void TilesBag::shuffleTiles() {
    /**
     * Concept/Idea of shuffleing vector was taken from 
     * https://www.techiedelight.com/shuffle-vector-cpp/s
     */
    // std::shuffle(std::begin(tilesVector), std::end(tilesVector), std::default_random_engine());
    std::shuffle(std::begin(tilesVector), std::end(tilesVector), std::random_device());
}