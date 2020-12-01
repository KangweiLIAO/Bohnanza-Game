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
#include "CardFactory.h"
#include "TradeArea.h"

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
};