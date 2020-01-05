//
//  main.cpp
//  CeaserCypherEncryptor
//
//  Created by adeeb mohammed on 05/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <string>


// more clear solution
// if we want to limit some numbers with in a certain limit then take the mode [ie reminder]
// if the number is less than that number, we get the actual value
// time complexity o(n) and space complexity is o(1)

char newLetter(char inputLetter,int key){
    int inputLetterInt = (int) inputLetter;
    int newLetterInt = inputLetterInt + key;
    // unicode of z is 122
    return (newLetterInt <= 122 )? (char)newLetterInt : char(newLetterInt % 122) + 96;
}


std::string caesarCypherEncryptor(std::string str, int key){
    key = key % 26; // 26 characters in english alphabet
    for(auto &ch : str){
        ch = newLetter(tolower(ch), key);
    }
    return str;
}



char shiftLetter(char inputLetter,int key){
    return (char) ((((int)inputLetter+key - 97)%26) + 97);
}

std::string caesarCypherEncryptorOrg(std::string str, int key) {
    for(auto i = 0; i < str.length(); ++i){
        str.at(i) = shiftLetter(tolower(str.at(i)),key);
    }
  return str;
}
int main(int argc, const char * argv[]) {
    std::cout << "Program for ceaser cypher encryption"<< std::endl;
    std::string str = "xyz";
    std::cout << "encyrption Result = " << caesarCypherEncryptor(str,2) << std::endl;
    std::cout << "ActualStrring = "<<str << std::endl;
    return 0;
}
