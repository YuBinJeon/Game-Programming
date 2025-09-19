#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

static double freq_from_A4_offset(int n) {
    return 440.0 * pow(2.0, n / 12.0);
}
static const int IDX8[8] = {0,2,4,5,7,9,11,12};

static int semitone_from_oct_idx(int octave, int idx8) {
    int semitone_from_C0 = octave * 12 + IDX8[idx8];
    int semitone_A4_from_C0 = 4 * 12 + 9;
    return semitone_from_C0 - semitone_A4_from_C0;
}

int main(void) {
    int octave = 4;
    int key;
    puts("숫자 1~8: C D E F G A B C, 0 또는 ESC: 종료");
    while (1) {
        key = getch();
        if (key == 27 || key == '0') break; // ESC or '0'
        if (key >= '1' && key <= '8') {
            int idx = key - '1'; // '1'→0
            int n = semitone_from_oct_idx(octave, idx);
            int f = (int)(freq_from_A4_offset(n) + 0.5);
            Beep(f, 400);
        }
    }
    return 0;
}
