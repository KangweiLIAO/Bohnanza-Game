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
    ostream os(&file);
    ifstream savedDeck("deck.txt");
    ifstream savedTable("table.txt");

    static CardFactory* factory;
    static Deck deck;

    Table* table;
    TradeArea* tradeArea = nullptr;
    DiscardPile* discardPile = nullptr;

    bool save = false;
    bool newGame = true;
    string* p1Name = new string();
    string* p2Name = new string();
    string* buff = new string();    // buffer to store the input of player
    cout << "**********************************" << endl;
    cout << "*       Welcome to the game      *" << endl;
    cout << "*             Made by            *" << endl;
    cout << "*   Kangwei Liao & Langqing Zou  *" << endl;
    cout << "**********************************\n" << endl;
    while (newGame || deck.numCards() > 0) {
        if (newGame) {
            if (savedDeck.good() && savedTable.good()) {
                cout << "\n***** Saves detected *****" << endl;
                readStringInput("Do you want to reload the game? (y/n): ", buff);
                if (*buff=="y") {
                    // Load and initialize table
                    factory = CardFactory::getFactory(savedDeck);
                    deck = factory->getDeck();
                    table = new Table(savedTable,factory);
                    savedDeck.close();
                    savedTable.close();
                    p1Name = table->getPlayer(1)->getName();
                    p2Name = table->getPlayer(2)->getName();
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
        if (save) {
            // Pause and save the game
            ofstream saveTable,saveDeck;
            saveTable.open("table.txt");
            saveDeck.open("deck.txt");
            factory->save(saveDeck);
            table->save(saveTable);
            saveTable.close();
            saveDeck.close();
            cout << "\n\n!!! Game saved !!!\n" << endl;
            return 1;
        }
        // Turns start
        for (int i=1; i<=2; i++) {
            Player* player = table->getPlayer(i);   // get current player
            string pName = *(player->getName());
            Card* cDraw = deck.draw();
            player->addCardToHand(cDraw);     // draw card to hand
            cout << "\n!!!!! " << pName << "'s turn START !!!!!\n" << endl;
            cout << "("+pName+") Draws a card from deck: "<< *cDraw << endl;
            cout << *table;
            // step 1:
            if (tradeArea->numCards() != 0) {
                // Add bean card from area?
                readStringInput("("+pName+") Do you want to get a card from the trade area? (y/n): ", buff);
                if (*buff=="y") {
                    // Add cards from trade area
                    string* card_name = new string();
                    vector<Card*> selectedCards;
                    while (*card_name != "q" && tradeArea->numCards() != 0) {
                        // while player want to get a card from trade area
                        Card* cBuff = nullptr;
                        cout << "("+pName+") Which card do you want to trade with?" << endl;
                        readStringInput("("+pName+") Please enter the name of it (e.g. Red/black) or enter 'q' to quit: ", card_name);
                        if (*card_name != "q") {
                            // if player entered a card name
                            cBuff = tradeArea->trade(*card_name);
                            if (!cBuff) cout << "("+pName+") The card name you entered is not valid." << endl;
                            else selectedCards.push_back(cBuff);
                        }
                    }
                    for(auto& card: selectedCards) {
                        // loop selected cards vector and add them to player's chains
                        if (player->cardMatch(card)) 
                            cout << "(" << pName << ") " << *card << " added to your chain." << endl;
                        else {
                            cout << "(" << pName << ") " << *card << " did not matched one of your chain." << endl;
                            readStringInput("("+pName+") Do you want to create a new chain for it? (y/n): ", buff);
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
                cout << "\n(" << pName << ") Hand: ";
                player->printHand(cout,true);
                readStringInput("\n("+pName+") Do you want to play one more card? (y/n): ", buff);
                if (*buff=="y") player->play();
                // step 4:
                readStringInput("("+pName+") Discard 1 card from hand? (y/n): ", buff);
                if (*buff=="y") player->discardHand(discardPile);
            } else
                cout << "\n("+pName+") Hand is empty, skip playing/discarding one more card." << endl;

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
                cout << "("+pName+") Draws a card from deck: "<< *cDraw << endl;
            }
        }
        readStringInput("\n***** Save game? *****\n(y/n): ", buff);
        if (*buff=="y") save = true;
    }
    cout << "\n\n!!!!!!!!!! The deck is empty, game over !!!!!!!!!!\n" << endl;
    cout << "The winner is ";
    if (table->win(*p1Name)) cout << p1Name << " !!!" << endl;
    else cout << p2Name << " !!!" << endl;
    return 0;
};