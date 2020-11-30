/**
 * File: Table.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

#ifndef TABLE_H
#define TABLE_H
#include "CardFactory.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Player.h"

using namespace std;

class Table{
    private:
        Player player1;
        Player player2;
        
    public:
        Table(istream&, const CardFactory*);
        bool win(string&);
        void printHand(bool);
        friend ostream& operator<<(ostream&,const Player&);
};

ostream& operator<<(ostream& os, const Player& player) {
    os << player;
    return os;
}

#endif