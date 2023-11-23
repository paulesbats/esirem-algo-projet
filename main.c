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
struct Deck* generateDeck(){
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
    return &tab[0];
}

void ShowHand(Player player){
    struct Deck *current = player.deck;
    while(current != NULL){
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
     deckP = generateDeck();
}


Choice userInput(){
    int answer = 0;
    int i = 0;
    printf("Quel action voulez vous faire ?\n");
    printf(" - Pour tirer une carte, rentrez 1\n");
    printf(" - Pour vous arreter, rentrez 2\n");
    printf(" - Pour doubler, rentrez 3\n");
    printf(" - Pour abandonner, rentrez 4");
    while(i == 0){
        scanf(" %c", &answer);
        if (answer == '1') {
            i = 1;
            return (HIT);
        } else if (answer == '2') {
            i = 1;
            return (STAND);
        } else if (answer == '3') {
            i = 1;
            return (DOUBLE);
        } else if (answer == '4') {
            i = 1;
            return (SURREND);
        }
        if (answer != ( 1 || 2 || 3 || 4 )) {
            printf("Le format de reponse n'est pas correcte, reessayer.");
        }
    }
}
int HandValue(Player player){
    int sum = 0;
    struct Deck *current = player.deck;
    while (current != NULL) {
        int value = current->card.valeur;
        sum+= value;
        current = current->next;
    };
    return sum;
}

void MainGame(){
    int choice;
    int i = 0;
    int mise = 0;
    Player player;
    player.value = 100;
    Player bank;
    bank.value = 0;
    struct Deck* deck;
    init(&bank,&player,deck);

    while(player.value >= 10){
        printf(" Vous possedez %d jetons",player.value);
        player.value =-10;
        mise =+ 10;
        printf("Nouveau tours ! \n");

        bank.deck = draw(deck);
        player.deck = draw(deck);

        ShowHand(player);

        while(i==0){
            choice = userInput();

            if(HandValue(player)<21){
                switch(choice) {
                    case HIT:
                        player.deck = draw(deck);
                        break;
                    case STAND:
                        i = 1;
                        break;
                    case DOUBLE :
                        mise = mise + 10;
                        player.deck = draw(deck);
                        break;
                    case SURREND:
                        player.value = player.value + 5;
                        i = 1;
                        player.deck = malloc(sizeof(struct Deck));
                        printf("Vous avez abandonnez et vous recuperez donc la moitier de votre mise");
                        break;
                }
            }
            else if(HandValue(player)>21){
                printf("Busted");
                i = 1;
            }
        }
    }



}

int main() {
    MainGame();
    return 0;
}

