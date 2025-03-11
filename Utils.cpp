#include "Utils.h"

std::string getUserStringInput() {
    std::string input = "";
    std::cout << USER_INPUT_SIGN;
    std::cin >> input;
    return input;
}

unsigned int getUserIntInput() {
    unsigned int input;
    std::cout << USER_INPUT_SIGN;
    std::cin >> input;
    return input;
}

bool containsInteger(const std::string string) {
    bool containsInteger = false;

    int i = 0;
    while(i < string.length() && !containsInteger) {
        // https://www.cplusplus.com/reference/cctype/isdigit/
        // isDigit checks if string contains integer
        if(std::isdigit(string[i])) {
            containsInteger = true; 
        }
        i++;
    }
    
    return containsInteger;
}

void toUppercase(std::string& string) {
    for(int i = 0; i < string.length(); i++) {
        // https://www.cplusplus.com/reference/locale/toupper/
        // Converts string to uppercase
        string[i] = std::toupper(string[i]);
    }
}

bool containSpecialCharacter(std::string string) {
    bool containSpecialCharacter = false;
   
    int i = 0;
    while(i < string.length() && !containSpecialCharacter) {
    
        // Checks is specific char is an alphabet
        bool isAnAlphabet = false;
        int j = 0;
        while(j < TOTAL_ALPHABETS && !isAnAlphabet) {
            if(string[i] == ALPHABETS[j]) { 
                isAnAlphabet = true;
            }
            j++;
        }

        // If its special character
        if(!isAnAlphabet) {
            containSpecialCharacter = true;
        }
        i++;
    }
    return containSpecialCharacter;
}
