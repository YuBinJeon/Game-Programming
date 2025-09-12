# 📘 게임프로그래밍(C언어) 1주차 실습 정리

## 1. 개발 환경

* **Dev-C++ (Orwell Dev-C++)** 사용 권장
  👉 [https://sourceforge.net/projects/orwelldevcpp/](https://sourceforge.net/projects/orwelldevcpp/)

---

## 2. 커서 제어

### gotoxy 함수

```c
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD Pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```

* 콘솔에서 원하는 좌표(x,y)에 출력 가능.
* 반복문으로 구구단 등 출력 정렬 가능.

---

## 3. 화면 지우기 & 입력

* **system("cls")** : 화면 지우기
* **getchar / getch / getche 차이**

  * `getchar` : 입력 버퍼 사용
  * `getch` : 입력 즉시(버퍼 X)
  * `getche` : 입력 즉시 + 화면에 표시

예제 – 입력 후 화면 지우기:

```c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char ch;
    printf("문자를 입력하고 Enter>");
    scanf("%c", &ch);
    system("cls");
    printf("입력된 문자 %c\n", ch);
    return 0;
}
```

---

## 4. ASCII 코드 & 스캔 코드

* **ASCII**: 문자와 대응하는 코드값 (예: 'a' → 97)
* **Scan Code**: 키보드 자체의 물리적 코드 (확장 키 포함, 방향키 등)

예제 – 코드 구분:

```c
#include <stdio.h>
#include <conio.h>
int main(void) {
    int chr;
    do {
        chr = getch();
        if (chr == 0 || chr == 0xe0) {
            chr = getch();
            printf("확장키 code=%d\n", chr);
        } else {
            printf("아스키 code=%d\n", chr);
        }
    } while(1);
}
```

---

## 5. 방향키 이동 함수

```c
void move_arrow_key(char key, int *x, int *y, int x_b, int y_b) {
    switch(key) {
        case 72: (*y)--; if (*y < 1) *y = 1; break;   // ↑
        case 75: (*x)--; if (*x < 1) *x = 1; break;   // ←
        case 77: (*x)++; if (*x > x_b) *x = x_b; break; // →
        case 80: (*y)++; if (*y > y_b) *y = y_b; break; // ↓
    }
}
```

* 콘솔 화면 내에서 `A` 문자를 방향키로 움직이는 프로그램 작성 가능.

---

## 6. 도형 그리기 (사각형)

* 텍스트 모드에서는 **확장 문자 코드(─│┌┘)** 이용.
* 크기를 입력받아 정사각형/직사각형 출력.

예제:

```c
void draw_square(int size) {
    unsigned char a=0xa6, b[7];
    for (int i=1; i<7; i++) b[i]=0xa0+i;
    // 테두리 출력 로직 (위-옆-아래)
}
```

---

## 7. 메뉴 만들기

### (1) 단일 메뉴

```c
int menu_display(void) {
    int select;
    system("cls");
    printf("간식 만들기\n\n");
    printf("1. 햄버거\n2. 스파게티\n3. 종료\n\n");
    printf("메뉴번호 입력>");
    select = getch() - 48; // char → int 변환
    return select;
}
```

* `switch-case`로 분기 → `hamburger()`, `spaghetti()` 호출.

### (2) 서브 메뉴 확장

* 햄버거 → 치킨버거, 치즈버거
* 스파게티 → 토마토, 크림

---

## 8. 난수 생성

* `rand() % 범위 + 시작값`
* **srand(time(NULL))** : 실행 시마다 다른 난수 발생

예제 – 1\~45 난수 6개 (중복 제거):

```c
int lotto[6];
for (int i=0; i<6; i++) {
    lotto[i] = rand() % 45 + 1;
    for (int j=0; j<i; j++) {
        if (lotto[i] == lotto[j]) { i--; break; }
    }
}
```

* 선택 정렬로 정렬 출력.

---

## 9. 가변 인수 함수

* `<stdarg.h>`의 `va_list`, `va_start`, `va_arg`, `va_end` 활용.
* `printf`, `scanf`도 내부적으로 이 구조 사용.

예제 – 합계 함수:

```c
#include <stdarg.h>
double sum(int count, ...) {
    double total = 0;
    va_list ap;
    va_start(ap, count);
    for (int i=0; i<count; i++)
        total += va_arg(ap, double);
    va_end(ap);
    return total;
}
```

---