#include <stdio.h>
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
    int ms = 500;
    // ascending
    for (int i = 0; i < 8; ++i) {
        int n = semitone_from_oct_idx(octave, i);
        int f = (int)(freq_from_A4_offset(n) + 0.5);
        Beep(f, ms);
        Sleep(50);
    }
    // descending
    for (int i = 7; i >= 0; --i) {
        int n = semitone_from_oct_idx(octave, i);
        int f = (int)(freq_from_A4_offset(n) + 0.5);
        Beep(f, ms);
        Sleep(50);
    }
    return 0;
}
