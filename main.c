#include <stdio.h>

struct card{ // structure pour chaque carte
    int valeur;
    enum Color color;
};

=======
//struct which can contain a undefined number of card
typedef struct{
    card card;
    card *next;
} Deck;

int main() {
    printf("Hello, World!\n");
    return 0;
}

