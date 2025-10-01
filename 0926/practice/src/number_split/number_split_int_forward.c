#include <stdio.h>
#include <math.h>

// 고자리→저자리: log10로 자리수 파악 후 몫/나머지
static void serial_number(long number) {
    if (number <= 0) return;
    int length = (int)(log10((double)number) + 1);
    for (int i = length; i >= 1; --i) {
        long base = (long)pow(10.0, i - 1);
        long digit = number / base;
        printf("%ld\n", digit);
        number -= digit * base;
    }
}

int main(void) {
    long n;
    printf("정수 입력> ");
    if (scanf("%ld", &n) != 1) return 0;
    printf("[고자리→저자리]\n");
    serial_number(n);
    return 0;
}
