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
#include "Table.h"

using namespace std;

int main() {
    static CardFactory* factory = CardFactory::getFactory();
    static Deck deck = factory->getDeck();
    ifstream saveFile("saves\\player.cfg");
    Table* table;
    bool pause = false;
    bool newGame = true;
    while (deck.numCards() > 0) {
        if (pause) {
            // Pause and save the game
            return 1;
        }
        if (saveFile.good()) {
            char buff;
            cout << "Save file detected, do you want to load the game? (y/n): ";
            cin >> buff;
            if (buff == 'y') {
                // Load and initialize table
                // table = 
                newGame = false;
            }
        } 
        if (newGame) {
            // Create new table
            string p1Name, p2Name;
            cout << "Please enter the name of player1: ";
            cin >> p1Name;
            cout << "Please enter the name of player2: ";
            cin >> p2Name;
            table = new Table(p1Name,p2Name,factory);
        }
        // Turns start
        TradeArea* tradeArea = table->getTradeArea();
        DiscardPile* discardPile = table->getDiscardPile(); 
        for (int i=1; i<=2; i++) {
            Player* player = table->getPlayer(i);
            Hand* hand = player->getHand();
            cout << *table;
            *hand += deck.draw();
            if (tradeArea->numCards() != 0) {
                // Add bean card from area?
                char buff;
                cout << "##### Trade Area #####\n" << *tradeArea;
                cout << "Do you want to get a card from trade area? (y/n): ";
                cin >> buff;
                if (buff == 'y') {
                    // Add cards from trade area
                    string buff;
                    vector<Card*> selectedCards;
                    while (buff != "q") {
                        cout << "Which card do you want to trade with?\nPlease enter the name of it (e.g. R) or enter 'q' to quit:" << endl;
                        cin >> buff;    // get card name
                        Card* cBuff = tradeArea->trade(buff);
                        if (!cBuff) cout << "The card name you entered is not valid." << endl;
                        else selectedCards.push_back(cBuff);
                    }
                    // loop selected cards vector and add them to player's chains
                    for(auto& card: selectedCards) 
                        player->chainMatch(card);
                    
                } else {
                    // Discards cards

                }
            }
        }
        char buff;
        cout << "Save the game? (y/n): ";
        cin >> buff;
        if (buff == 'y') pause = true;
    }
    return 0;
};