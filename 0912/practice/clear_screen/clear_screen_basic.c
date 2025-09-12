#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch;
    printf("문자를 입력하고 Enter> ");
    scanf(" %c", &ch); // 앞에 공백 추가
    system("cls");
    printf("입력된 문자: %c\n", ch);
    printf("아무 키나 누르면 종료합니다...");
    getchar(); // 버퍼 비우기
    getchar(); // 입력 대기
    return 0;
}