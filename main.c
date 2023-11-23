#include <stdio.h>
#include <stdlib.h>

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
}Deck;

typedef enum Choice{HIT,STAND,DOUBLE,SURREND}Choice;

//struct which contain a deck and a value
typedef struct Player {
    Deck *deck;
    int value;
} Player;


void ShowHand(Player player){
    Deck *current = player.deck;
    while(current != NULL){
        int value = current->card.valeur;
        Color color = current->card.color;
        printf("%d de ", value);
        switch (color) {
            case (HEART):
                printf("Coeur");
                break;
            case (SPADE):
                printf("Pique");
                break;
            case (DIAMOND):
                printf("Carreau");
                break;
            case (CLOVER):
                printf("Trèfle");
                break;
        }
        current = current->next;
    }
};

int main() {
    return 0;
}
