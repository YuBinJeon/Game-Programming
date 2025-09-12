#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int lotto[6];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 6; i++) {
        lotto[i] = rand() % 45 + 1;
        for (int j = 0; j < i; j++) {
            if (lotto[i] == lotto[j]) { i--; break; }
        }
    }
    for (int i = 0; i < 6; i++) printf("%2d\n", lotto[i]);
    return 0;
}
