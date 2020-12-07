/**
 * @file: Main.h
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
    filebuf file;
    ifstream savedDeck("saves\\deck.cfg");
    ifstream savedTable("saves\\table.cfg");

    static CardFactory* factory;
    static Deck deck;

    Table* table;
    TradeArea* tradeArea = nullptr;
    DiscardPile* discardPile = nullptr;

    bool pause = false;
    bool newGame = true;
    string* p1Name = new string();
    string* p2Name = new string();
    string* buff = new string();    // buffer to store the input of player
    
    while (deck.numCards() > 0) {
        if (newGame) {
            if (savedDeck.good() && savedTable.good()) {
                readStringInput("Saves found, do you want to reload the game? (y/n): ", buff);
                if (*buff=="y") {
                    // Load and initialize table
                    factory = CardFactory::getFactory(savedDeck);
                    table = new Table(savedTable,factory);
                }
            }
            if (*buff!="y") {
                // Create new table
                factory = CardFactory::getFactory();
                deck = factory->getDeck();
                readStringInput("Please enter the name of player1: ", p1Name);
                readStringInput("Please enter the name of player2: ", p2Name);
                table = new Table(*p1Name,*p2Name,factory);
            }
        }
        if (tradeArea==nullptr || discardPile==nullptr) {
            tradeArea = table->getTradeArea();
            discardPile = table->getDiscardPile();
            newGame = false;
        }
        if (pause) {
            // Pause and save the game
            return 1;
        }
        // Turns start
        for (int i=1; i<=2; i++) {
            Player* player = table->getPlayer(i);   // get current player
            Card* cDraw = deck.draw();
            player->addCardToHand(cDraw);     // draw card to hand
            cout << "\n\n!!!!! " << player->getName() << "'s turn START !!!!!\n" << endl;
            cout << "("+player->getName()+") Draws a card from deck: "<< *cDraw << endl;
            cout << *table;
            // step 1:
            if (tradeArea->numCards() != 0) {
                // Add bean card from area?
                readStringInput("("+player->getName()+") Do you want to get a card from the trade area? (y/n): ", buff);
                if (*buff=="y") {
                    // Add cards from trade area
                    string* card_name = new string();
                    vector<Card*> selectedCards;
                    while (*card_name != "q" && tradeArea->numCards() != 0) {
                        // while player want to get a card from trade area
                        Card* cBuff = nullptr;
                        cout << "("+player->getName()+") Which card do you want to trade with?" << endl;
                        readStringInput("("+player->getName()+") Please enter the name of it (e.g. Red/black) or enter 'q' to quit: ", card_name);
                        if (*card_name != "q") {
                            // if player entered a card name
                            cBuff = tradeArea->trade(*card_name);
                            if (!cBuff) cout << "("+player->getName()+") The card name you entered is not valid." << endl;
                            else selectedCards.push_back(cBuff);
                        }
                    }
                    for(auto& card: selectedCards) {
                        // loop selected cards vector and add them to player's chains
                        if (player->cardMatch(card)) 
                            cout << "(" << player->getName() << ") " << *card << " added to your chain." << endl;
                        else {
                            cout << "(" << player->getName() << ") " << *card << " did not matched one of your chain." << endl;
                            readStringInput("("+player->getName()+") Do you want to create a new chain for it? (y/n): ", buff);
                            if (*buff=="y") {
                                if (player->createChain(card)==nullptr) 
                                    *discardPile += card;   // discard the mismatched card if can't create new chain
                            }
                        }
                    }
                }
                tradeArea->discardAll(discardPile); // discards all cards in trade area
            }
            
            // step 2:
            player->play();              // play the topmost card
            
            // step 3:
            if (player->getHandSize() != 0) {
                cout << "\n(" << player->getName() << ") Hand: ";
                player->printHand(cout,true);
                readStringInput("\n("+player->getName()+") Do you want to play one more card? (y/n): ", buff);
                if (*buff=="y") player->play();
                // step 4:
                readStringInput("("+player->getName()+") Discard 1 card from hand? (y/n): ", buff);
                if (*buff=="y") player->discardHand(discardPile);
            } else
                cout << "\n("+player->getName()+") Hand is empty, skip playing/discarding one more card." << endl;

            // step 5:
            cout << "\n!!! 3 Cards added to trade area !!!" << endl;
            for(int i=0; i<3; i++) *tradeArea += deck.draw();   // draw 3 cards and add to trade area
            while (!discardPile->isEmpty() && tradeArea->legal(discardPile->top())) {
                Card* cBuff = discardPile->pickUp();
                cout << "Card " << *cBuff << " popped from discard pile and added to trade area." << endl;
                *tradeArea += cBuff;            // add the legal card to trade area
            }
            cout << "---------- Trade Area ----------\n" << *tradeArea << endl;
            if(tradeArea->numCards() != 0) tradeArea->trade(player);   // prompt player to make decision on each card in trade area
            // step 6:
            for(int i=0; i<2; i++) {
                Card* cDraw = deck.draw();
                player->addCardToHand(cDraw);     // draw card to hand
                cout << "("+player->getName()+") Draws a card from deck: "<< *cDraw << endl;
            }
        }
        readStringInput("\nSave the game? (y/n): ", buff);
        if (*buff=="y") pause = true;
    }
    cout << "\n\n!!!!!!!!!! The deck is empty !!!!!!!!!!\n" << endl;
    if (table->win(*p1Name)) 
        cout << "The winner is " << p1Name << "!!!" << endl;
    else cout << "The winner is " << p2Name << "!!!" << endl;
    return 0;
};