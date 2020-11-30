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
#include "DiscardPile.h"

using namespace std;

int main() {
    CardFactory factory;
    Deck deck = factory.getDeck();
    DiscardPile pile;
    // filebuf fb;
    // fb.open ("test.txt",ios::out);
    // ostream os(&fb);
    // write ... in os
    // fb.close();

};