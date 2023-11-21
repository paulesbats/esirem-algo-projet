#include <stdio.h>

//struct which can contain a undefined number of card
typedef struct{
    card card;
    card *next;
} Deck;

int main() {
    printf("Hello, World!\n");
    return 0;
}
