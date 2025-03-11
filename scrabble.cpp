#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem> 

#include "LinkedList.h"
#include "Board.h"
#include "Gameplay.h"
#include "Tile.h"
#include "TilesBag.h"
#include "Player.h"
#include "PlayerHand.h"
#include "Utils.h"

#define EXIT_SUCCESS    0

void init(); 
void printMainMenu();
void credits();
void newGame();
// void loadGame();
std::vector<std::string> splitString(std::string string, char letter);

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;
   init();
   //  std::vector<std::vector<std::string> > vec( ROW , std::vector<std::string> (COL, " A ")); 

   return EXIT_SUCCESS;
}

// Only runs once at start of the game  
void init() {
   std::cout << std::endl << "Welcome to Scrabble" << std::endl;
   std::cout << LINE_BREAK << std::endl;
   printMainMenu();
}


void printMainMenu(){
   bool flag = false;
   while (!flag){
      std::cout << std::endl;
      std::cout << "Menu" << std::endl;
      std::cout << "----" << std::endl;
      std::cout << "1. New Game" << std::endl;
      std::cout << "2. Load Game" << std::endl;
      std::cout << "3. Credits" << std::endl;
      std::cout << "4. Quit" << std::endl << std::endl;

      unsigned int userInput = getUserIntInput();
      
      if (userInput == 1 ){
         newGame();
         flag = true;
      }
      if (userInput == 2 ){
         // loadGame();
         flag = true;
      }
      if (userInput == 3 ){
         credits();
      }
      if (userInput == 4 ){
         std::cout<< "GoodBye" <<std::endl;
         flag = true;
      }
      else{
         std::cout<< "Invalid Input Number" <<std::endl;
      }
   }


}

void credits(){
   std::cout<< LINE_BREAK << LINE_BREAK <<std::endl;
   std::cout<< "Name: Saicharan Kannan\nStudent Number: s3814854\nEmail: s3814854@student.rmit.edu.au" <<std::endl;
   std::cout<< " " <<std::endl;
   std::cout<< "Name: Sahibjeet Singh\nStudent Number: s3842316\nEmail: s3842316@student.rmit.edu.au" <<std::endl;
   std::cout<< LINE_BREAK << LINE_BREAK <<std::endl;
}

void newGame(){
   std::string player1;
   std::string player2;

   std::cout << std::endl << "Starting New Game" << std::endl << std::endl;

   // Player1
   bool validName = false;
   while(!validName) {
      std::cout<< "Enter a name for player 1" <<std::endl;
      player1 = getUserStringInput();
   
      // Validation 
      if(!containsInteger(player1)) {
         // Converts string to uppercase
         toUppercase(player1);
         
         // Checks for special characters in string
         if(containSpecialCharacter(player1) == false) {
            validName = true;
         }  
         else {
            std::cout<< "Player name should not contain special letters" <<std::endl;
         }
      }
      else {
         std::cout<< "Player name should not contain number" <<std::endl;
      }

      std::cout << std::endl;
   }

   // Player 2
   validName = false;
      while(!validName) {
      std::cout<< "Enter a name for player 2" <<std::endl;
      player2 = getUserStringInput();
   
      // Validation 
      if(!containsInteger(player2)) {
         // Converts string to uppercase
         toUppercase(player2);
         
         // Checks for special characters in string
         if(!containSpecialCharacter(player2)) {
            validName = true;
         }  
         else {
            std::cout<< "Player name should not contain special letters" <<std::endl;
         }
      }
      else {
         std::cout<< "Player name should not contain number" <<std::endl;
      }

      std::cout << std::endl;
   }

   std::cout << "Let's Play!" << std::endl;

   TilesBag* tilesBag = new TilesBag();
   tilesBag->fillBag();

   Player* p1 = new Player(player1, tilesBag);
   p1->getPlayerHand()->fillPlayerHand();
   Player* p2 = new Player(player2, tilesBag);
   p2->getPlayerHand()->fillPlayerHand();
   // std::cout << p1 << std::endl;
   // Gameplay* gameplay = new Gameplay(player1, player2);
   Gameplay* gameplay = new Gameplay(p1, p2, tilesBag);

   gameplay->startGame();
   
} 

// /**
//  * Loads current game from a file
//  */
//  void loadGame() {
//    // Opens the file
//    std::cout << std::endl << "Enter the path to filename from which load a game" << std::endl;
//    std::string filePath = getUserStringInput();
//    std::cout << std::endl;

   



//    try {
//       std::ifstream file(filePath);

//       if(file) {
//          // Player1 variables
//          std::string player1Name;
//          int player1Score;
//          std::string player1Hand;

//          // Player1 variables
//          std::string player2Name;
//          int player2Score;
//          std::string player2Hand;

//          // Board Variable
//          std::string boardArray[MAX_ROW];
         
//          // TilesBag variables
//          std::string tilesBagString;

//          // Current player name variable 
//          std::string currentPlayer;

//          // File reading 
//          std::vector<std::string> tempReadVec;
//          std::string line;
//          while(std::getline(file, line)) {
//             tempReadVec.push_back(line);
//          }

//          int lineCount = 0;
//          // Player1 Reading init variables
//          player1Name = tempReadVec[lineCount++];
//          /**
//           * Convert String to int
//           * https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/
//           */
//          player1Score = std::stoi(tempReadVec[lineCount++]);
//          player1Hand = tempReadVec[lineCount++];

//          // Player 2 Reading init variables
//          player2Name = tempReadVec[lineCount++];
//          player2Score = std::stoi(tempReadVec[lineCount++]);
//          player2Hand = tempReadVec[lineCount++];

//          // Board Reading  init variables
//          for(int i = 0; i < MAX_ROW; i++) {
//             boardArray[i] = tempReadVec[lineCount++];
//          } 

//          // TileBag Reading init Variables
//          tilesBagString = tempReadVec[lineCount++];

//          // Current Player init variables
//          currentPlayer = tempReadVec[lineCount++];

//          file.close();

//          // Splitting String
//          std::vector<std::string> player1HandVec = splitString(player1Hand, ',');
//          std::vector<std::string> player2HandVec = splitString(player2Hand, ',');
//          std::vector<std::string> tilesBagVec = splitString(tilesBagString, ',');

//          // Creates new Bag
//          TilesBag* tilesBag = new TilesBag();
//          for(int i = 0; i < tilesBagVec.size(); i++) {
//             // Splits value
//             std::string temp = tilesBagVec[i];

//             char letter = temp[0];
//             // https://stackoverflow.com/questions/16492463/wrong-result-of-casting-string-to-int-c
//             int value = temp[2] - '0';

//             Tile* tempTile = new Tile(letter, value);
//             tilesBag->addTile(tempTile);
//          }
         
//          // Creates Players
//          Player* player1 = new Player(player1Name, tilesBag);
//          Player* player2 = new Player(player2Name, tilesBag);

//          // Creates Player1 Cards in Hand
//          for(int i = 0; i < player1HandVec.size(); i++) {
//             // Splits value
//             std::string temp = player1HandVec[i];

//             char letter = temp[0];
//             int value = temp[2] - '0';

//             Tile* tempTile = new Tile(letter, value);
//             player1->getPlayerHand()->addTile(tempTile);
//          }

//          // Creates Player2 Cards in Hand
//          for(int i = 0; i < player2HandVec.size(); i++) {
//             // Splits value
//             std::string temp = player2HandVec[i];

//             char letter = temp[0];
//             int value = temp[2] - '0';

//             Tile* tempTile = new Tile(letter, value);
//             player2->getPlayerHand()->addTile(tempTile);
//          }

//          Gameplay* gameplay = new Gameplay(player1, player2, tilesBag);
         
//          // Board TO DO
//          for(int i = 0; i < MAX_ROW; i++) { 

//             std::vector<std::string> boardVec = splitString(boardArray[i], ',');

//             for(int j = 0; j < MAX_COL; j++) {
               
//                // Splits value
//                std::string temp = boardVec[j];

//                char letter = temp[1];

//                if(temp != "   ") {
//                   gameplay->getBoard()->setTileOnBoard(i, j, letter);
//                }
//             }
//          }

//          // CURRENT PLAYER TO DO
//          if(player1->getName() == currentPlayer) {
//             gameplay->setCurrentPlayer(player1);
//          } else {
//             gameplay->setCurrentPlayer(player2);
//          }

//          // starts game
//          gameplay->startGame();
         
//       } else {
//          std::cout << "File at: " << filePath << " Not Found" << std::endl; 
//          printMainMenu();
//       }

//    } catch (std::exception) {
//       std::cout << "Error with file" << std::endl; 
//       printMainMenu();
//    }
  
// }

// std::vector<std::string> splitString(std::string string, char letter) {
//    std::vector<std::string> splittedVec;
//    std::stringstream ss(string);

//    while (ss.good()) {
//       std::string substr;
//       std::getline(ss, substr, letter);
//       splittedVec.push_back(substr);
//    }

//    return splittedVec;
// }

