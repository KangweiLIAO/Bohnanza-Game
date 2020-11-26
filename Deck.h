/*
Group 8:
Teammates:  Kangwei Liao: 8568800
            Langqing Zou: 300035036
*/

/*********** File : "Deck.h" **********/
#include "Card.h"
#include <vector>

class Deck {
    public:
        Deck(): number(0) {}
        int numCards() {return number;} 
        void empty() {number = 0;}
        void newDeck();
        void shuffle();
        // Card take();
        // Card lookIn(int no);
    private :
        vector<Card> deck;      // hold cards
        int number;             // number of card in deck
};

// When a card is not found by index, throw:
struct CardNotFoundException : public std::exception {
	const char * what() const throw () {
    	return "Card Not Found Exception - The given index exceeded deck number.";
    }
};

// When taking card from an empty deck, throw:
struct DeckEmptyException : public std::exception {
	const char * what() const throw () {
    	return "Deck Empty Exception - Taking card from empty deck.";
    }
};

void Deck::newDeck() {
    // Create a new deck that corresponds to the 104 cards
    
}

// void Deck::shuffle() {
//     // Swap card 104 times
//     if (number==0) return;
//     Card buff;
//     srand(time(0));
//     for (int i = 0; i < 104; i++) {
//         int randCardID = 1+(rand()%51);     // Generate a random int between [1, 51]
//         buff = deck[randCardID];
//         deck[randCardID] = deck[i];
//         deck[i] = buff;
//     }
// }

// Card Deck::take() {
//     // Take a card from the back
//     Card c;
//     if (number > 0) {
//         c = deck[number-1];
//         number--;
//         return c;
//     }
//     // If card not found, throw:
//     throw DeckEmptyException();
// }

// Card Deck::lookIn(int no) {
//     Card c;      // An error card with value 0
//     if (no > 0 && no < number+1){
//         return deck[no-1];
//     }
//     // If card not found, throw:
//     throw CardNotFoundException();
// }