/**
 * @file: Hand.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the hand of a player.
 * 
 * Methods:
 *  - Hand(istream&, const CardFactory*)
 *  - Hand& operator+=(Card*)
 *  - Card* play()
 *  - Card* top()
 *  - Card* operator[](int)
 *  - friend ostream& operator<< (ostream&, const Hand&)
 */

#ifndef HAND_H
#define HAND_H

// std libraries:
#include <list>
#include <queue>
// project headers:
#include "CardFactory.h"

using namespace std;

class Hand {
    private:
        queue<Card*,list<Card*> > hand;   // list with queue adapter 
    public:
        // constructor:
        Hand() {};
        Hand(istream&, const CardFactory*);
        // member functions:
        Card* play(); 
        Card* at(int);
        Card* top() {return hand.front();}  ///returns but does not remove the top card from the player's hand.
        int size() const {return hand.size();}
        // operators:
        Card* operator[] (int);
        ///adds the card to the rear of the hand.
        Hand& operator+= (Card*);
        friend ostream& operator<< (ostream&, const Hand&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the hand from file.
 * @param is An istream address
 * @param factory A const CardFactory
 */
Hand::Hand(istream& is, const CardFactory* factory){
    Deck deck = factory->getFactory()->getDeck();
    string line,s;
    while(getline(is,line)){
        auto delimiterPos = line.find("=");
        auto name = line.substr(0, delimiterPos);
        auto value = line.substr(delimiterPos + 1);

        if(name=="hand"){
            string s;
            vector<string> res; //save for each word
            stringstream input(value);
            while(input>>s) res.push_back(s);
            for(int i=0;i<res.size();i++){
                if(res[i]=="R"){
                    hand.push(new Red());
                }else if(res[i]=="C"){
                    hand.push(new Chili());
                }else if(res[i]=="G"){
                    hand.push(new Green());
                }else if(res[i]=="B"){
                    hand.push(new Blue());
                }else if(res[i]=="S"){
                    hand.push(new Stink());
                }else if(res[i]=="g"){
                    hand.push(new Garden());
                }else if(res[i]=="s"){
                    hand.push(new Soy());
                }else if(res[i]=="b"){
                    hand.push(new Black());
                }
            }
        }
    }
}

Card* Hand::at(int i) {
    int count = 0;
    Card* cBuff = nullptr;
    queue<Card*,list<Card*> > buff;
    buff.swap(hand);
    while (!buff.empty()) {
        Card* c = buff.front();
        if(count==i) cBuff = c;
        buff.pop();
        hand.push(c);
        count++;
    }
    if (cBuff==nullptr) throw CardNotFoundException();
    return cBuff;
}

/**
 * @brief Pop and return the top card in hand
 * @return A pointer to the card just popped
 */
Card* Hand::play() {
    Card* card = hand.front();
    hand.pop();
    return card;
}

/**
 * @brief Returns and removes the card at specified index
 * @param i Index for a card in hand
 * @return  A pointer to the card at index i
 */
Card* Hand::operator[] (int i) {
    int count = 0;
    Card* cBuff = nullptr;
    queue<Card*,list<Card*> > buff;
    buff.swap(hand);
    while (!buff.empty()) {
        Card* c = buff.front();
        if(count==i) {
            cBuff = c;
            buff.pop();
        } else {
            buff.pop();
            hand.push(c);
        }
        count++;
    }
    if (!cBuff) throw CardNotFoundException();
    return cBuff;
}

inline Hand& Hand::operator+= (Card* card) {
    hand.push(card);
    return *this;
}

/**
 * @brief Insert hand into ostream
 * @param os An ostream
 * @param h A hand needs to be printed
 * @return Ostream with hand inserted
 */
ostream& operator<< (ostream& os, Hand& h) {
    if (h.size()==0) {
        os << "Empty";
        return os;
    }
    for (size_t i=0; i<h.size(); i++) os << i+1 << ":" << *(h.at(i)) << "\t";
    return os;
}

#endif