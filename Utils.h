#ifndef ASSIGN2_UTILS_H
#define ASSIGN2_UTILS_H

#include <iostream>
#include <string>

#define LINE_BREAK                  "-------------------"
#define USER_INPUT_SIGN             "> "
#define MAX_TILES_QUANTITY          98
#define SCRABBLE_TILES_FILE_NAME    "ScrabbleTiles.txt"
#define MAX_ROW 15
#define MAX_COL 15
#define MAX_TILES_IN_HAND           7
#define ALPHABETS                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define TOTAL_ALPHABETS             26
#define BOARD_HEAD                  "   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14 "
#define BOARD_HEAD_BREAK            "  ------------------------------------------------------------"

typedef std::vector<std::vector<std::string> > twoDVector;

/**
 * Takes user input and returns an String input value
 */
std::string getUserStringInput();

/**
 * Takes user input as int and returns an unsigned int
 */
unsigned int getUserIntInput();

/**
 * Checks if a string contains integer
 */
bool containsInteger(const std::string string);

/**
 * Converts string to uppercase
 */
void toUppercase(std::string& string);

/**
 * Checks if string contains special character like ( & ^...
 */
bool containSpecialCharacter(std::string string);


#endif // ASSIGN2_UTILS_H