# Scrabble Game

A command-line-based Scrabble game for two players.

## How to Clone and Run the Game

1. **Clone the repository**:
   ```bash
   git clone <repository-url>

cd scrabble

make scrabble

or

g++ -Wall -Werror -std=c++14 -g -O -c scrabble.cpp

g++ -Wall -Werror -std=c++14 -g -O -o scrabble Tile.o Node.o LinkedList.o scrabble.o Board.o Utils.o Player.o Gameplay.o PlayerHand.o TilesBag.o

./scrabble


## How to Play

Start a New Game: Choose option 1 to start a new game.

Enter Player Names: Input names for both players.

Place Tiles: Use the command place <letter> at <position> (e.g., place D at A1). 

End Turn: Type place Done to end your turn and switch players. 

The game will display the board and your current score after each turn.

Enjoy playing Scrabble!


## Key Features & Technical Highlights

- **TileBag Class**: 
  - Efficiently implemented using a **LinkedList** to manage tile data, ensuring fast tile drawing operations with constant-time complexity.
  - Key Methods: `fillBag()`, `drawTile()`, `addTile()`, `get()`, `getSize()`, `clearBag()`.
  - **Shuffle Algorithm**: Developed an optimized shuffle method to introduce randomness and enhance game dynamics.

- **PlayerHand Class**:
  - Utilizes a **LinkedList** to store and manage player tiles, ensuring efficient tile management with constant-time operations for adding/removing tiles.
  - Key Methods: `drawTile()`, `addTile()`, `get()`, `getSize()`, `fillPlayerHand()`, `replaceTile()`, `printHand()`.
  - Focused on creating a smooth user experience with fast tile access and hand updates.

- **Board Design**:
  - Implemented a highly effective **2D vector-based board** to handle tile placement with ease and flexibility.
  - Optimized board layout using a string representation, providing efficient tile display and placement without complex 2D arrays.
  - Resolved complexity challenges and focused on keeping the board interaction efficient.

- **Gameplay Logic**:
  - Developed the core gameplay mechanics, integrating **LinkedLists** for player hands and **vectors** for the board to optimize gameplay flow.
  - Bug Fixes: Ensured smooth gameplay by handling edge cases such as input errors (non-integer input) and EOF scenarios with enhanced game termination mechanisms.
  - **Save/Load Game**: Designed dynamic save/load functionality, supporting multi-player games with scalable and reusable code.

- **Optimizations & Problem-Solving**:
  - **Code Refactoring**: Refactored critical gameplay methods to improve maintainability and efficiency, ensuring smoother gameplay.
  - Reduced repetitive code, leveraging loops and vector-based data structures to simplify future expansions (e.g., adding more players).
  - Solved complex problems with game state management and multi-player game logic, ensuring the system could scale easily.


This project demonstrates strong proficiency in data structures (LinkedLists, vectors) and algorithm optimization, combined with a practical approach to problem-solving and efficient game design. The codebase is designed to be easily extensible for future feature additions, making it adaptable for a wide range of applications.



 Author: Saicharan Kannan 
 
 Author: Sahibjeet Singh

