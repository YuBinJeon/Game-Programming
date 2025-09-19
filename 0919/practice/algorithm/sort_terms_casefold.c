#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 2048
#define MAX_LEN   256

typedef struct {
    char original[MAX_LEN];
    char lower[MAX_LEN];
} Item;

static void to_lower_copy(char* dst, const char* src) {
    for (; *src; ++src, ++dst) *dst = (char)tolower((unsigned char)*src);
    *dst = '\0';
}

static int cmp_item(const void* a, const void* b) {
    const Item* x = (const Item*)a;
    const Item* y = (const Item*)b;
    int c = strcmp(x->lower, y->lower);
    if (c != 0) return c;
    return strcmp(x->original, y->original); // tie-breaker
}

int main(void) {
    FILE* fp = fopen("terms.txt", "r");
    if (!fp) {
        fprintf(stderr, "terms.txt 파일을 같은 폴더에 두세요.\n");
        return 1;
    }
    Item arr[MAX_ITEMS];
    int n = 0;
    while (n < MAX_ITEMS && fgets(arr[n].original, MAX_LEN, fp)) {
        size_t len = strlen(arr[n].original);
        while (len && (arr[n].original[len-1] == '\n' || arr[n].original[len-1] == '\r')) {
            arr[n].original[--len] = '\0';
        }
        to_lower_copy(arr[n].lower, arr[n].original);
        ++n;
    }
    fclose(fp);
    qsort(arr, n, sizeof(Item), cmp_item);
    for (int i = 0; i < n; ++i) puts(arr[i].original);
    return 0;
}
