#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { int order; int number; } Card;

static void init_deck(Card d[]) {
    int k = 0;
    for (int ord = 0; ord < 4; ++ord)
        for (int num = 1; num <= 13; ++num)
            d[k++] = (Card){ord, num};
}

static void print_deck(const Card d[]) {
    for (int i = 0; i < 52; ++i) {
        int n = d[i].number;
        char ch = (n==1)?'A':(n==11)?'J':(n==12)?'Q':(n==13)?'K':0;
        if (ch) printf("%c ", ch);
        else    printf("%2d ", n);
        if ((i+1)%13==0) puts("");
    }
}

int main(void) {
    Card deck[52];
    init_deck(deck);
    srand((unsigned)time(NULL));
    for (int i = 0; i < 52; ++i) {
        int rnd;
        do { rnd = rand() % 52; } while (rnd == i);
        Card t = deck[i]; deck[i] = deck[rnd]; deck[rnd] = t;
    }
    print_deck(deck);
    return 0;
}
