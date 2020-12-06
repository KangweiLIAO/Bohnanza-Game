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

const char read(string s) {
    char buff;
    cout << s;
    cin.get(buff);
    cin.ignore();
    cin.clear();
    return buff;
}

int main() {
    static CardFactory* factory = CardFactory::getFactory();
    static Deck deck = factory->getDeck();
    ifstream saveFile("saves\\player.cfg");
    Table* table;
    TradeArea* tradeArea = nullptr;
    DiscardPile* discardPile = nullptr;
    bool pause = false;
    bool newGame = true;
    while (deck.numCards() > 0) {
        if (newGame) {
            char buff;
            if (saveFile.good()) {
                cout << "Saves found, do you want to reload the game? (y/n): ";
                cin >> buff;
                if (buff=='y') {
                    // Load and initialize table
                    // table = new Table(Reconstructor);
                }
            }
            if (!buff || buff=='n') {
                // Create new table
                string p1Name, p2Name;
                cout << "Please enter the name of player1: ";
                cin >> p1Name;
                cout << "Please enter the name of player2: ";
                cin >> p2Name;
                table = new Table(p1Name,p2Name,factory);
                table = new Table("p1Name","p2Name",factory);
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
        char buff;                                  // store the decision of y/n decision
        for (int i=1; i<=2; i++) {
            Player* player = table->getPlayer(i);   // get current player
            player->addCardToHand(deck.draw());     // draw card to hand
            cout << *table << endl;
            // step 1:
            if (tradeArea->numCards() != 0) {
                // Add bean card from area?
                cout << "##### Trade Area #####\n" << *tradeArea;
                cout << "Do you want to get a card from trade area? (y/n): ";
                // cin >> buff;
                if (buff == 'y') {
                    // Add cards from trade area
                    string card_name;
                    vector<Card*> selectedCards;
                    while (card_name != "q") {
                        Card* cBuff = nullptr;
                        cout << "Which card do you want to trade with?" << endl;
                        cout << "Please enter the name of it (e.g. R) or enter 'q' to quit:" << endl;
                        cin >> card_name;    // get card name
                        if (card_name != "q") cBuff = tradeArea->trade(card_name);
                        if (!cBuff) cout << "The card name you entered is not valid." << endl;
                        else selectedCards.push_back(cBuff);
                    }
                    // loop selected cards vector and add them to player's chains
                    for(auto& card: selectedCards) {
                        if (player->chainMatch(card)) cout << *card << " added to your chain." << endl;
                        else {
                            cout << *card << " did not matched." << endl;
                            *discardPile += card;   // discard the mismatched card
                        }
                    }
                    if (tradeArea->numCards() != 0) {
                        // if have cards left in trade area:
                        tradeArea->discardAll(discardPile);
                    }
                } else tradeArea->discardAll(discardPile);      // discards all cards in trade area
                
                // step 2:
                player->play();              // play the topmost card
                cout << *table << endl;
                // step 3:
                cout << "Do you want to play one more card? (y/n)" << endl;
                cin >> buff;
                if (buff == 'y') player->play();
                // step 4:
                cout << "Discard 1 card from hand? (y/n)" << endl;
                cin >> buff;
                if (buff == 'y') player->discardHand(discardPile);

                // step 5:
                for(int i=0; i<3; i++) *tradeArea += deck.draw();   // draw 3 cards and add to trade area
                while (tradeArea->legal(discardPile->top()))
                    *tradeArea += discardPile->pickUp();            // add the legal card to trade area
                // prompt player to make decision on each card in trade area:
                tradeArea->trade(player);
                // step 6:
                for(int i=0; i<2; i++) player->addCardToHand(deck.draw());
            }
        }
        cout << "Save the game? (y/n): ";
        cin >> buff;
        if (buff == 'y') pause = true;
    }
    return 0;
};