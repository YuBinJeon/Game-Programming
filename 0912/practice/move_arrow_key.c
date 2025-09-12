#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define X_MAX 79  // 콘솔 가로 최대 열
#define Y_MAX 24  // 콘솔 세로 최대 행

void gotoxy(int x, int y) {
    COORD Pos = { (SHORT)(x - 1), (SHORT)(y - 1) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void move_arrow_key(int key, int *x, int *y, int x_b, int y_b) {
    switch (key) {
        case 72: (*y) -= 1; if (*y < 1) *y = 1; break;       // ↑
        case 75: (*x) -= 1; if (*x < 1) *x = 1; break;       // ←
        case 77: (*x) += 1; if (*x > x_b) *x = x_b; break;   // →
        case 80: (*y) += 1; if (*y > y_b) *y = y_b; break;   // ↓
        default: break;
    }
}

int main(void) {
    int x = 10, y = 5;
    int key;
    system("cls");
    do {
        gotoxy(x, y);
        printf("A");
        key = getch();
        if (key == 0 || key == 0xe0) key = getch(); // 확장키 보정
        move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
        system("cls");
    } while (key != 27); // ESC 종료
    return 0;
}
