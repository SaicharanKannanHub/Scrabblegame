#include "Node.h"
#include "Tile.h"

Node::Node(Tile* tile, Node* next)
{ 
   // TODO
   this->tile = tile;
   this->next = next;
}

Node::Node(Node& other)
{
   // TODO
   this->tile = other.tile;
   this->next = other.next;
}

Node::~Node() {
   delete tile;
}
