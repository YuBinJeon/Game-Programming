#include <stdio.h>

// 저자리→고자리: %10, /10
static void reverse_number(long number) {
    if (number <= 0) return;
    while (number > 0) {
        printf("%ld\n", number % 10);
        number /= 10;
    }
}

int main(void) {
    long n;
    printf("정수 입력> ");
    if (scanf("%ld", &n) != 1) return 0;
    printf("[저자리→고자리]\n");
    reverse_number(n);
    return 0;
}
