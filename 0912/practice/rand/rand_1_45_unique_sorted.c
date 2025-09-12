#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void selection_sort(int r[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) if (r[j] < r[min]) min = j;
        int temp = r[min];
        r[min] = r[i];
        r[i] = temp;
    }
}

int main(void) {
    int lotto[6];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 6; i++) {
        lotto[i] = rand() % 45 + 1;
        for (int j = 0; j < i; j++) {
            if (lotto[i] == lotto[j]) { i--; break; }
        }
    }
    selection_sort(lotto, 6);
    for (int i = 0; i < 6; i++) printf("%2d\n", lotto[i]);
    return 0;
}
