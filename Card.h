/*
Group 8:
Teammates:  Kangwei Liao: 8568800
            Langqing Zou: 300035036
*/

/*********** File : "Card.h" **********/ 
#include <iostream>
#include <cassert> //for assert()

using namespace std;

// Abstract class:
class Card {
    public:
        virtual string getName() {return name;}
        // Pure virtual functions:
        virtual int getCardsPerCoin(int coins) = 0;
        virtual void print(ostream& out) = 0;
    private:
        string name;
};

// Concrete classes:
class Blue : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Blue";
};

class Chili : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Chili";
};

class Stink : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Stink";
};

class Green : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Green";
};

class Soy : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Soy";
};

class Black : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Black";
};

class Red : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Red";
};

class Garden : public Card {
    public:
        int getCardsPerCoin(int coins) {

        };
        void print(ostream& out) {

        };
    private:
        string name = "Garden";
};