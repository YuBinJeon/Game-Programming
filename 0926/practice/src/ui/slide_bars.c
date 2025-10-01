#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

static void gotoxy(int x, int y) {
    COORD Pos = { (SHORT)(x - 1), (SHORT)(y - 1) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

static void draw_rectangle(int cols, int rows) {
    putchar('+'); for (int i=0;i<cols;i++) putchar('-'); puts("+");
    for (int r=0;r<rows;r++) {
        putchar('|'); for (int c=0;c<cols;c++) putchar(' '); puts("|");
    }
    putchar('+'); for (int i=0;i<cols;i++) putchar('-'); puts("+");
}

static void move_arrow_key(int key, int* x, int* y, int x_b, int y_b) {
    switch (key) {
    case 72: (*y)--; if (*y < 1) *y = 1;        break; // ↑
    case 80: (*y)++; if (*y > y_b) *y = y_b;    break; // ↓
    case 75: (*x)--; if (*x < 1) *x = 1;        break; // ←
    case 77: (*x)++; if (*x > x_b) *x = x_b;    break; // →
    default: break;
    }
}

static void draw_horizontal_slide(int x, int y, int length, const char *s) {
    int real_len = length / 2;
    gotoxy(1, y);
    draw_rectangle(real_len + 1, 1);
    gotoxy(x + 2, y + 1);
    printf("%s", s);
    gotoxy(real_len * 2 + 2, y - 1);
    printf("%2d", x);
}

static void draw_vertical_slide(int x, int y, int length, const char *s) {
    gotoxy(x, 1);
    draw_rectangle(1, length);
    gotoxy(x + 2, y + 1);
    printf("%s", s);
    gotoxy(x + 6, length + 1);
    printf("%2d", y);
}

int main(void) {
    const char *slide = "■";
    int x = 1, y = 1;
    int h_len, v_len;

    printf("슬라이드바 표시\n\n");
    printf("수평 길이(최대 70) 입력> ");  if (scanf("%d", &h_len) != 1) return 0;
    printf("수직 길이(최대 19) 입력> ");  if (scanf("%d", &v_len) != 1) return 0;
    system("cls");

    int key;
    do {
        draw_vertical_slide(1, y, v_len, slide);
        draw_horizontal_slide(x, v_len + 3, h_len, slide);
        key = getch();
        if (key == 0 || key == 0xE0) key = getch(); // 확장키
        move_arrow_key(key, &x, &y, h_len, v_len);
    } while (key != 27); // ESC
    return 0;
}
