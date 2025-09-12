#include <stdio.h>
#include <stdarg.h>

double sum(int count, ...) {
    double total = 0.0;
    va_list ap;
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total;
}

int main(void) {
    printf("합계 = %lf\n", sum(2, 10.5, 20.23));
    printf("합계 = %lf\n", sum(5, 10.3, 245.67, 0.51, 198345.764, 1.0));
    return 0;
}
