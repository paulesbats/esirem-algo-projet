#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
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
void generateDeck(struct Deck *ptr){
    Card tab[52];
    for(int i = 0; i < 52; i++) {
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
        card.valeur = i % 13 + 1;
        tab[i] = card;
    }
    srand(time(NULL));
    for(int i = 0; i < 9000; i++) {
        int n = rand() % 50;
        Card tmp = tab[n];
        tab[n] = tab[n+1];
        tab[n+1] = tmp;
    }
    struct Deck *current = ptr;
    for(int i = 0; i<51; i++) {
        struct Deck *tmp = malloc(sizeof(struct Deck));
        current->card = tab[i];
        current->next = tmp;
        current = tmp;
    }
    current->next = NULL;
}

void ShowHand(Player player) {
    struct Deck *current = player.deck;
    while (current != NULL) {
        int value = current->card.valeur;
        Color color = current->card.color;
        printf("%d de ", value);
        switch (color) {
            case (HEART):
                printf("Coeur\n");
                break;
            case (SPADE):
                printf("Pique\n");
                break;
            case (DIAMOND):
                printf("Carreau\n");
                break;
            case (CLOVER):
                printf("Trèfle\n");
                break;
        }
        current = current->next;
    }
}


void init(Player* bank, Player* player1,struct Deck* deckP ){
     player1->value = 50;
     generateDeck(deckP);
}

int main() {
    /* test 
    Player *player = malloc(sizeof(Player));
    struct Deck *deck = malloc(sizeof(struct Deck));
    generateDeck(deck);
    player->deck = deck;
    ShowHand(*player);
    */
    return 0;
}
