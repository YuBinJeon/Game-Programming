#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int order;   // 0:♠, 1:◆, 2:♥, 3:♣
    int number;  // 1..13 (1:A, 11:J, 12:Q, 13:K)
    const char* shape;
} Card;

static const char* SHAPES[4] = {"\u2660", "\u25C6", "\u2665", "\u2663"}; // ♠ ◆ ♥ ♣

static const char* num_to_str(int n) {
    switch (n) {
        case 1:  return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return NULL;
    }
}

int main(void) {
    setlocale(LC_ALL, "");
    Card deck[52];
    int idx = 0;
    for (int ord = 0; ord < 4; ++ord) {
        for (int num = 1; num <= 13; ++num) {
            deck[idx].order = ord;
            deck[idx].number = num;
            deck[idx].shape = SHAPES[ord];
            idx++;
        }
    }
    // 출력
    for (int i = 0; i < 52; ++i) {
        const char* s = num_to_str(deck[i].number);
        if (s) printf("%s%-2s ", deck[i].shape, s);
        else   printf("%s%-2d ", deck[i].shape, deck[i].number);
        if ((i+1)%13 == 0) puts("");
    }
    return 0;
}
