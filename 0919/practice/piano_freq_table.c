#include <stdio.h>
#include <math.h>

// 12-TET: f = 440 * 2^(n/12), where n: semitone offset from A4
static double freq_from_A4_offset(int semitone) {
    return 440.0 * pow(2.0, semitone / 12.0);
}

// diatonic scale indices (C D E F G A B C): 0,2,4,5,7,9,11,12 from C
static const int IDX8[8] = {0,2,4,5,7,9,11,12};

// map (octave, diatonic index 0..7) to semitone offset from A4
static int semitone_from_oct_idx(int octave, int idx8) {
    int semitone_from_C0 = octave * 12 + IDX8[idx8]; // C0 기준
    int semitone_A4_from_C0 = 4 * 12 + 9; // A4 = C4 + 9
    return semitone_from_C0 - semitone_A4_from_C0;
}

int main(void) {
    printf("A4 = 440Hz 기준 12-TET 주파수표 (C 옥타브 기준)\n");
    for (int oct = 1; oct <= 5; ++oct) {
        printf("Octave %d: ", oct);
        for (int i = 0; i < 8; ++i) {
            int n = semitone_from_oct_idx(oct, i);
            double f = freq_from_A4_offset(n);
            printf("%7.2f ", f);
        }
        puts("");
    }
    return 0;
}
