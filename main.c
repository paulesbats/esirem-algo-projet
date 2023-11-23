#include <stdio.h>
//Debut du projet

typedef enum Color{SPADE, HEART, DIAMOND, CLOVER}Color;

typedef struct Card{ // structure pour chaque carte
    int valeur;
    Color color;
} Card;

//struct which can contain a undefined number of card
typedef struct Deck{
    Card card;
    struct Deck *next;
} Deck;


typedef enum Choice{HIT,STAND,DOUBLE,SURREND}Choice;

//struct which contain a deck and a value
typedef struct Player {
    Deck deck;
    int value;
} Player;

void init(Player* bank, Player* player1,Deck* deckP ){
     player1->value = 50;
     deckP = generateDeck();
}

void ShowHand(){
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
