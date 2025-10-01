# 📘 게임프로그래밍(C언어) · 3주차 실습

<p align="left">
  <img alt="C" src="https://img.shields.io/badge/C-00599C?logo=c&logoColor=white">
  <img alt="Windows" src="https://img.shields.io/badge/Windows-0078D6?logo=windows&logoColor=white">
  <img alt="MinGW" src="https://img.shields.io/badge/MinGW-gcc-green">
  <img alt="License" src="https://img.shields.io/badge/edu-lab-blue">
</p>

> 숫자 분해, 디지털 숫자 출력, 슬라이드 바, 3×3 도형 회전/이동을 단계적으로 구현합니다.

## 👀 빠른 미리보기 (Preview)

<details>
<summary><b>1) 숫자 분해</b> — 고자리→저자리 / 저자리→고자리</summary>

```
정수 입력> 10234
[고자리→저자리]
1
0
2
3
4

[저자리→고자리]
4
3
2
0
1
```
</details>

<details>
<summary><b>2) 디지털 숫자 (4×5)</b></summary>

```
정수 입력> 250
■■■■      ■■■■  ■■■■
    ■      ■         ■
■■■■      ■■■■  ■  ■
■             ■  ■  ■
■■■■      ■■■■  ■■■■
```
</details>

<details>
<summary><b>3) 슬라이드 바</b> — ← → ↑ ↓ 로 이동</summary>

```
+------------------------------+      +--+
| ■                            |      |  |
|                              |      |■ |
+------------------------------+      +--+
 x=12                                   y=3
```
</details>

<details>
<summary><b>4) 3×3 도형 이동·회전</b> — 화살표 이동, <kbd>Space</kbd> 회전</summary>

```
      □
      □
  □ □ □
```
</details>

---

## 📂 실습 목록

| 구분 | 파일 | 핵심 포인트 |
|---|---|---|
| 숫자 문자열 | `number_split_string_forward.c` | 문자열 인덱싱 |
| 〃 | `number_split_string_reverse.c` | 역순 출력 |
| 숫자 정수연산 | `number_split_int_forward.c` | `log10`, `pow` 이용 |
| 〃 | `number_split_int_reverse.c` | `%10`, `/10` 루프 |
| 재귀 | `number_split_recursion.c` | 호출/반환 순서 활용 |
| 디지털 숫자 | `digital_number_print.c` | 4×5 도트 매핑, 라인 출력 |
| UI 위젯 | `slide_bars.c` | `gotoxy`, 화살표 입력 |
| 도형 | `shape_move_rotate.c` | 회전(전치+인덱스), 이동 경계처리 |

---

## ⚙️ 빌드

> Windows + MinGW(gcc) 예시

```bash
gcc -O2 -Wall number_split_string_forward.c -o number_split_string_forward.exe
gcc -O2 -Wall number_split_string_reverse.c -o number_split_string_reverse.exe
gcc -O2 -Wall number_split_int_forward.c    -lm -o number_split_int_forward.exe
gcc -O2 -Wall number_split_int_reverse.c    -o number_split_int_reverse.exe
gcc -O2 -Wall number_split_recursion.c      -o number_split_recursion.exe
gcc -O2 -Wall digital_number_print.c        -o digital_number_print.exe
gcc -O2 -Wall slide_bars.c                  -o slide_bars.exe
gcc -O2 -Wall shape_move_rotate.c           -o shape_move_rotate.exe
```

> MSVC도 가능. 일부 예제는 `windows.h`, `conio.h`, `kbhit`, `Sleep`, `gotoxy` 사용.

---

## 🔍 체크포인트
- 입력 값이 0 또는 음수일 때 분기 처리 확인
- 콘솔 좌표 경계(`x[1..75]`, `y[2..23]`)에서 오버런 방지
- 슬라이드 바 길이 입력값 범위: 수평 ≤ 70, 수직 ≤ 19

---

## 🧪 학습 목표
- 문자열 vs 정수 연산 vs 재귀 접근 비교
- 콘솔 UI 요소 그리기와 입력 이벤트 처리
- 작은 행렬 회전 로직(시계 90°) 구현

---

## 📎 참고
- 예제는 수업 자료를 기반으로 재구성. 필요 시 주석 참고.
