#ifndef ASSIGN2_TILE_BAG_H
#define ASSIGN2_TILE_BAG_H

#include <vector>

class Tile;
class LinkedList;

class TilesBag {
    public:
        // Constructor/CopyConstructor/Destructor
        TilesBag();
        TilesBag(const TilesBag& other);
        ~TilesBag();

        /**
         * Fills bag with tiles 
         */
        void fillBag();

        /**
         * Draws tile from front of the linked list
         * returns a new tile as a new tile so no need to delete 
         */
        Tile* drawTile();

        /**
         * Adds Tile to the end of the linked list
         */
        void addTile(Tile* tile);

        /**
         * Return tile at index can be used for printing 
         */
        Tile* get(unsigned int index);

        /**
         * Retuns number of Tiles in bag
         */
        unsigned int getSize() const;

        /**
         * Removes all Tiles from bag
         */
        void clearBag();


    private:
        /**
         * Reads data form ScrabbleTiles.txt and adds it to Tile Vector
        */
        void loadFile();

        /**
         * Shuffles the tiles in random order
         */
        void shuffleTiles();

        std::vector<Tile*> tilesVector;
        LinkedList* tileList;
        unsigned int size;

};


#endif // ASSIGN2_TILE_BAG_H