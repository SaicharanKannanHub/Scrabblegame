#ifndef ASSIGN2_PLAYER_HAND_H
#define ASSIGN2_PLAYER_HAND_H

#include <vector>

class LinkedList;
class Tile;
class TilesBag;

class PlayerHand {
    public:
        PlayerHand(TilesBag* tileBag);
        ~PlayerHand();

        /**
         * Allocates 7 tiles to the hand
         */
        void fillPlayerHand();

        /**
         * Searches for letter in the list
         * returns the found tile as a new tile so no need to delete 
         * if no tile found throws an exception
         */
        Tile* drawTile(char letter);

        /** 
         * Replaces current tile with new tile from bag
         */
        bool replaceTile(char letter);

        /**
         * Adds Tile to the end of the linked list
         */
        void addTile();

        /**
         * Overloaded method can be used when loading data from file
         */
        void addTile(Tile* tile);

        /**
         * Prints the whole player hand
         */
        void printHand();

        /**
         * Return tile at index
         */
        Tile* get(unsigned int index);

        /**
         * Return amount of tiles in players hand
         */
        unsigned int getSize() const;

    private:
        TilesBag* tilesBag;
        LinkedList* playerHandList;
        unsigned int size;
};

#endif // ASSIGN2_PLAYER_HAND_H