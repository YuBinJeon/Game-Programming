#include <stdio.h>

void draw_basic_square(void) {
    unsigned char a = 0xA6, b[7]; // 완성형 선문자
    for (int i = 1; i < 7; i++) b[i] = 0xA0 + i;
    // ┌ ┐
    printf("%c%c", a, b[3]);
    printf("%c%c", a, b[4]);
    printf("\n");
    // └ ┘
    printf("%c%c", a, b[6]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

int main(void) {
    draw_basic_square();
    return 0;
}
