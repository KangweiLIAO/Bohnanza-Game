/**
 * File: Main.h
 * Description: 
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

// std libraries:
#include <fstream>

// project headers:
// #include "Table.h"
#include "MyException.h"
#include "CardFactory.h"
#include "Hand.h"

using namespace std;

int main() {
    CardFactory factory;
    Deck deck = factory.getDeck();
    cout << deck << endl;

    // write file:
    // filebuf fb;
    // fb.open ("save.txt",ios::out);
    // ostream os(&fb);
    // write ... in os
    // fb.close();

    // read file:
    // filebuf fb;
    // if (fb.open ("save.txt",ios::in)) {
    //     istream is(&fb);
    //     while (is) cout << char(is.get());
    //     fb.close();
    // }

    // Chain<Black> black;
    // try {
    //     for(auto& card: deck) {
    //         string type = typeid(*card).name();
    //         // cout << type << endl;
    //         if(type == typeid(Black).name()) black += card;
    //     }
    // } catch(const IllegalTypeException& e) {
    //     cout << "Not black" << endl;
    // }
    // cout << black.getSize() << endl;

};