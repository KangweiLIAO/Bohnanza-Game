#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <string>

void readStringInput(string info, string* buff) {
    buff->clear();
    cout << info;
    while(!(cin >> *buff)){
        cin.clear();                // clear cin buffer
        cin.ignore(100, '\n');      // clear cin buffer
        cout << "Please enter a valid input: ";
    }
}
#endif

#ifndef SAVE_H
#define SAVE_H

#include <map>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class Save {
    
};

#endif