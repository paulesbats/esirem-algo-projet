#include <stdio.h>

typedef struct card{ // structure pour chaque carte
    int valeur;
    enum Color color;
} card;


//struct which can contain a undefined number of card
typedef struct Deck{
    card card;
    card *next;
} Deck;

int main() {
    printf("Hello, World!\n");
    return 0;
}

