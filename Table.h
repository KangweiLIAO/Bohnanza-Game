/**
 * File: Table.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * @brief
 * This class will hold two objects of type Player, the Deck and the 
 * DiscardPile, as well as the TradeArea.
 * 
 * Methods:
 * - Table(istream&, const CardFactory*)
 * - bool win(string&)
 * - void printHand(bool)
 * - friend ostream& operator<<(ostream&,const Table&)
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
        friend ostream& operator<<(ostream&,const Table&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the Table from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Table::Table(istream& is, const CardFactory* factory) {

}

/**
 * @brief Returns true when a player has won.
 * @param s The address of the name of player
*/
bool Table::win(string& s){

}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 * or all of the player's hand (with argument true)
 * @param flag a boolean
*/

void Table::printHand(bool flag){

}

/**
 * @brief Insert table to an std::ostream.
 * @param os An ostream
 * @param player A table needs to be printed
*/
ostream& operator<<(ostream& os, const Table& table) {
    os << table;
    return os;
}

#endif