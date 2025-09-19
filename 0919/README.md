# 📘 게임프로그래밍(C언어) 2주차 실습 정리

## 1. 빌드/실행 환경
* **Windows + MinGW(gcc)** 또는 **MSVC(cl.exe)**
* 일부 예제는 `windows.h`, `conio.h`, `Beep`, `Sleep` 사용
* 컴파일 예시(MinGW):
```bash
gcc -O2 -Wall card_struct_print.c -o card_struct_print.exe
gcc -O2 -Wall card_shuffle_v1.c -o card_shuffle_v1.exe
gcc -O2 -Wall card_shuffle_v2.c -o card_shuffle_v2.exe
gcc -O2 -Wall piano_freq_table.c -lm -o piano_freq_table.exe
gcc -O2 -Wall piano_beep_scale.c -o piano_beep_scale.exe
gcc -O2 -Wall piano_keyboard_numbers.c -o piano_keyboard_numbers.exe
gcc -O2 -Wall linked_list_replay.c -o linked_list_replay.exe
gcc -O2 -Wall stack_push_pop.c -o stack_push_pop.exe
gcc -O2 -Wall sort_terms_casefold.c -o sort_terms_casefold.exe
```

---

## 2. 카드 표시(구조체 기반)
* 52장 덱 생성. 모양(♠◆♥♣)과 번호(1..13) 매핑
* A,J,Q,K는 문자로 표시
```c
typedef struct { int order; int number; } Card;
// 출력시 1->'A', 11->'J', 12->'Q', 13->'K' 처리
```

---

## 3. 카드 섞기(shuffle)
### (1) v1: 임의 인덱스와 스왑
```c
for (int i=0; i<52; ++i) {
    int rnd = rand()%52;
    swap(deck[i], deck[rnd]);
}
```
### (2) v2: 자기 자신과 스왑 방지
```c
int rnd; do { rnd = rand()%52; } while (rnd==i);
swap(deck[i], deck[rnd]);
```

---

## 4. 음계 주파수(12-TET)
* 공식: `f = 440 * 2^(n/12)` (A4 기준)
* C 옥타브 기준 도레미파솔라시도 주파수 테이블 출력
```c
double f = 440.0 * pow(2.0, semitone/12.0);
```

---

## 5. Beep로 음계 재생
* 4옥타브 도~도(상행 후 하행)
```c
int ms=500;
for (int i=0;i<8;i++) Beep(freq(i), ms);
for (int i=7;i>=0;i--) Beep(freq(i), ms);
```

---

## 6. 숫자 키로 음 재생
* `getch()`로 '1'~'8' 입력시 해당 음 재생
* `ESC` 또는 '0' 입력시 종료
```c
int key = getch();
if (key>='1' && key<='8') Beep(freq(key-'1'), 400);
```

---

## 7. 연결 리스트(정순/역순 출력)
* 키 입력을 노드로 저장
* 종료 후 정순, 재귀로 역순 출력
```c
typedef struct Node{ int key; struct Node* next; } Node;
```

---

## 8. 스택(push/pop)
* 단순 연결 리스트 기반 LIFO
```c
void push(Stack* s, int v); int pop(Stack* s, int* out);
```

---

## 9. 대소문자 무시 정렬
* `terms.txt` 한 줄당 한 용어
* 소문자 사본으로 정렬, 원문 출력
```c
qsort(arr, n, sizeof(Item), cmp_casefold);
```

---

## 10. 포함 파일
* `card_struct_print.c`, `card_shuffle_v1.c`, `card_shuffle_v2.c`
* `piano_freq_table.c`, `piano_beep_scale.c`, `piano_keyboard_numbers.c`
* `linked_list_replay.c`, `stack_push_pop.c`
* `sort_terms_casefold.c`
* `terms.txt`(사용자 준비)
