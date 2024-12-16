#include <stdio.h>
#include <stdlib.h>

struct DNA{
    char string[10000];
    int order;
};

int compare(const void *a, const void *b) {
    struct DNA *dna_a = (struct DNA *)a;
    struct DNA *dna_b = (struct DNA *)b;
    
    // 比較 order，若相等則按原始位置排序
    if (dna_a->order == dna_b->order) {
        return 0; // 保持順序不變
    } else {
        return dna_a->order - dna_b->order; // 按 order 升序排序
    }
}

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n, m;
        scanf("%d %d", &n, &m);

        struct DNA DNA_array[m];

        for (int i = 0; i < m; i++) {
            scanf("%s", DNA_array[i].string);
            DNA_array[i].order = 0;

            for (int j = 0; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (DNA_array[i].string[j] > DNA_array[i].string[k]) {
                        DNA_array[i].order++;
                    }
                }
            }
        }

        // 使用 qsort 排序，並傳入比較函式
        qsort(DNA_array, m, sizeof(struct DNA), compare);

        for (int i = 0; i < m; i++) {
            printf("%s\n", DNA_array[i].string);
        }
    }

    return 0;
}
