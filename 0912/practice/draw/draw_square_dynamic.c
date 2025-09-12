#include <stdio.h>

void draw_square(int size) {
    int i, j;
    unsigned char a = 0xA6, b[7];
    for (i = 1; i < 7; i++) b[i] = 0xA0 + i;

    // 상단
    printf("%c%c", a, b[3]);
    for (i = 0; i < size; i++) printf("%c%c", a, b[1]);
    printf("%c%c\n", a, b[4]);

    // 중간
    for (i = 0; i < size; i++) {
        printf("%c%c", a, b[2]);
        for (j = 0; j < size; j++) printf("  ");
        printf("%c%c\n", a, b[2]);
    }

    // 하단
    printf("%c%c", a, b[6]);
    for (i = 0; i < size; i++) printf("%c%c", a, b[1]);
    printf("%c%c\n", a, b[5]);
}

int main(void) {
    int n;
    printf("정사각형 길이(최대 37) 입력> ");
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) n = 0;
    if (n > 37) n = 37;
    draw_square(n);
    return 0;
}
