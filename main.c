#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//Debut du projet

typedef enum Color{SPADE, HEART, DIAMOND, CLOVER}Color;

typedef struct Card{ // structure pour chaque carte
    int valeur;
    Color color;
} Card;

//struct which can contain a undefined number of card
struct Deck{
    Card card;
    struct Deck *next;
}Deck;

typedef enum Choice{HIT,STAND,DOUBLE,SURREND}Choice;

//struct which contain a deck and a value
typedef struct Player {
    struct Deck *deck;
    int value;
} Player;

//generate the deck
struct Deck generateDeck(){
    struct Deck tab[52];
    for(int i = 0; i < 52; i++) {
        struct Deck tmpDeck;
        Card card;
        if(i % 4 == 0){
            card.color = SPADE;
        }
        if(i % 4 == 1){
            card.color = HEART;
        }
        if(i % 4 == 2){
            card.color = DIAMOND;
        }
        if(i % 4 == 3){
            card.color = CLOVER;
        }
        card.valeur = i % 13;
        tmpDeck.card = card;
        tab[i] = tmpDeck;
    }
    srand(time(NULL));
    for(int i = 0; i < 1000; i++) {
        int n = rand() % 50;
        struct Deck tmp = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = tmp;
    }
    for(int i = 0; i<51; i++) {
        tab[i].next = &tab[i+1];
    }
    tab[52].next = NULL;
    return tab[0];
}

void ShowHand(Player player){
    struct Deck *current = player.deck;
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
}


void init(Player* bank, Player* player1,Deck* deckP ){
     player1->value = 50;
     deckP = generateDeck();
}

int main() {
    return 0;
}
