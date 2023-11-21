#include <stdio.h>


typedef enum Color{SPADE, HEART, DIAMOND, CLOVER}Color;

typedef struct card{ // structure pour chaque carte
    int valeur;
    Color color;
} card;

//struct which can contain a undefined number of card
typedef struct Deck{
    card card;
    card *next;
} Deck;


typedef enum choice{HIT,STAND,DOUBLE,SURREND}choice;

//struct which contain a deck and a value
typedef struct Player {
    Deck deck;
    int value;
} Player;


int main() {
    printf("Hello, World!\n");
    return 0;
}
