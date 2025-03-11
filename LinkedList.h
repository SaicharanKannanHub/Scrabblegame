
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

class Node;
class Tile;

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   /**
    * Copy Constructor
    */
   LinkedList(const LinkedList& other);

   /**
    * Return the current size of the Linked List.
    * Unsigned because the values world be positive integer
    */
   unsigned int size() const;

   /**
    * Returns the value at the given index.
    * const because it wont change the value of anything
    */
   Tile* get(const unsigned int index) const;

   /**
    * Add the value to the front of the Linked List
    */
   void addFront(Tile* tile);

   /**
    * Add the value to the back of the Linked List
    */
   void addBack(Tile* tile);

   /**
    * Returns the value at front of the list
    * const because it wont change the value of anything
    */
   Tile* getFront() const;

   /**
    * Returns the value at bacl of the list
    * const because it wont change the value of anything
    */
   Tile* getBack() const;

   /**
    * Remove the value at the front of the Linked List
    */
   void removeFront();

   /**
    * Remove the value at the back of the Linked List
    */
   void removeBack();

   /**
    * Removes the value at the given index.
    */
   void remove(unsigned int index);

   /**
    * Removes all values from the Linked List
    */
   void clear();


private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
