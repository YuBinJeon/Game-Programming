#include <stdio.h>
#include <string.h>

int main(void) {
    char number[64];
    printf("금액(숫자 문자열) 입력> ");
    if (scanf("%63s", number) != 1) return 0;
    int length = (int)strlen(number);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c\n", number[i]);
    }
    return 0;
}
