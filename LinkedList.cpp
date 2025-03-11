#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Tile.h"

LinkedList::LinkedList() {
   head = nullptr;
   // TODO
}

LinkedList::LinkedList(const LinkedList& other){
    head = nullptr;
    for(int i = 0; i < other.size(); ++i) {
        Tile* tile = new Tile(*other.get(i));
        addBack(tile);
    }
}

LinkedList::~LinkedList() {
   clear();
}

unsigned int LinkedList::size() const {

   int length = 0;

   Node* current = head;
   while(current != nullptr){
      ++length;
      current = current->next;
   }

   return length;
}

Tile* LinkedList::get(const unsigned int index) const { 
   
   Tile* tile = nullptr;

   if(index < size()) {
      
      int counter = 0;
      Node* current = head;

      while(counter < index){
         ++counter;
         current = current->next;
      }

      tile = current->tile;
   }

   return tile;
}

void LinkedList::addFront(Tile* tile) {
   Node* node = new Node(tile, head);
   head = node;
}

void LinkedList::addBack(Tile* tile) {
   Node* node = new Node(tile, nullptr);

   if(head == nullptr){
      head = node;
   } else {
      Node* current = head;
      while(current->next != nullptr){
         current = current->next;
      }
      current->next = node;
   }
}

Tile* LinkedList::getFront() const {
   Tile* frontTile = nullptr;

   if(head != nullptr){
      frontTile = head->tile;
   } else {
      throw std::runtime_error("Nothing to return at front");
   }
   
   return frontTile;
}

Tile* LinkedList::getBack() const {
   Node* lastTile = head;
   
   if(head != nullptr){
      while(lastTile->next != nullptr) {
         lastTile = lastTile->next;
      }
    } else {
      throw std::runtime_error("Nothing to return at back");
   }

    return lastTile->tile;
}

void LinkedList::removeFront() {
   if(head != nullptr){
      Node* toDelete = head;
      head = head->next;

      delete toDelete;

   } else{
      throw std::runtime_error("Nothing to remove at front");
   }
}

void LinkedList::removeBack() {
    
   if(head != nullptr){
      Node* current = head;
      Node* prev = nullptr;

      while(current->next != nullptr){
         prev = current;
         current = current->next;
      }

      if(prev == nullptr){
         head = nullptr;
      } else{
         prev->next = nullptr;
      } 

      delete current;
   } else{
      throw std::runtime_error("Nothing to remove at back");
   }

}


void LinkedList::remove(unsigned int index) {

   if(index < size()) {
      if(head != nullptr){
         int counter = 0;

         Node* current = head;
         Node* prev = nullptr;

         while(counter != index){
            ++counter;
            prev = current;
            current = current->next;
         }

         if(prev == nullptr){
            head = current->next;
         } else {
            prev->next = current->next;
         }

         delete current;
      }
   }
}

void LinkedList::clear(){
    while(head != nullptr){
        removeFront();
    }
}
