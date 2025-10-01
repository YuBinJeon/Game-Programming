#include <stdio.h>

static void serial_number(long n) { // 고자리→저자리
    if (n > 0) {
        serial_number(n / 10);
        printf("%ld\n", n % 10);
    }
}
static void reverse_number(long n) { // 저자리→고자리
    printf("%ld\n", n % 10);
    if (n / 10 > 0) reverse_number(n / 10);
}

int main(void) {
    long n;
    printf("정수 입력> ");
    if (scanf("%ld", &n) != 1) return 0;
    printf("[재귀] 고자리→저자리\n");
    serial_number(n);
    printf("\n[재귀] 저자리→고자리\n");
    reverse_number(n);
    return 0;
}
