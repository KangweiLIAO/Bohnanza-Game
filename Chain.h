/**
 * @file Chain.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class is a derived class of {Chain_Base} and holds the chains of a player.
 * 
 * Methods:
 *  - Chain(istream&, const CardFactory*)
 *  - int sell()
 *  - Chain<T>& operator+=(Card*)
 *  - friend ostream& operator<< (ostream&, const Chain&)
 */

#ifndef CHAIN_H
#define CHAIN_H

// std libraries:
#include <vector>
#include <type_traits>
// project headers:
#include "Chain_Base.h"

using namespace std;

template <class T> 
class Chain : public Chain_Base {
    protected:
        void print(ostream&) const override;
    public:
        // constructors
        Chain() {this->name = typeid(T).name();}
        Chain(istream&, const CardFactory*);
        // member functions
        int sell() override;
        size_t getSize() {return this->chain.size();}
        // operators
        Chain<T>& operator+= (Card*) override;
        Card* operator[] (int i) {return this->chain[i];}
        // friend ostream& operator<< (ostream&, const Chain<T>&) {};
};

template <class T>
Chain<T>::Chain(istream& is, const CardFactory* factory) {
    Deck deck = factory->getFactory()->getDeck();
    string line,s;
    while(getline(is,line)){
        auto delimiterPos = line.find("=");
        auto name = line.substr(0, delimiterPos);
        auto value = line.substr(delimiterPos + 1);

        if(name=="chain1" || name=="chain2" || name=="chain3"){
            string s;
            vector<string> res; //save for each word
            stringstream input(value);
            while(input>>s){
                res.push_back(s);
            }
            if(res[0]=="R"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Red());
                }
            }else if(res[0]=="C"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Chili());
                }
            }else if(res[0]=="G"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Green());
                }
            }else if(res[0]=="B"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Blue());
                }
            }else if(res[0]=="S"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Stink());
                }
            }else if(res[0]=="g"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Garden());
                }
            }else if(res[0]=="s"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Soy());
                }
            }else if(res[0]=="b"){
                for(int i=0; i<stol(res[1])-1;i++){
                    operator+=(new Black());
                }
            }
        }
    }
}

/**
 * @brief Counts the number cards in the current chain and returns the number coins 
 *        according to the function {Card::getCardsPerCoin}. 
 * @return The price of this chain
 */
template <class T>
inline int Chain<T>::sell() {
    T card;
    return card.getCardsPerCoin(this->chain.size());
}

/**
 * @brief Adds a card to the Chain. If the run-time type does not match the template type of the chain and 
 *        exception of type IllegalType will be raised.
 * @return A pointer of this chain
 * @throw IllegalTypeException() if type mismatched
 */
template <class T>
inline Chain<T>& Chain<T>::operator+= (Card* card){
    if (this->match(card)) {
        this->chain.push_back(card);
        return *this;
    } else throw IllegalTypeException();
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
template <class T>
void Chain<T>::print(ostream& os) const {
    for(auto& card: this->chain) 
        os << *card << " ";
}

#endif