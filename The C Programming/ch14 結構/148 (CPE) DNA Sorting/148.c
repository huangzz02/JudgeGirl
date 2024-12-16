#include <stdio.h>

struct DNA{
    char string[10000];
    int order;
};

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

        for (int i = 1; i < m; i++) {
            struct DNA temp = DNA_array[i];
            int j = i - 1;

            while (j >= 0 && DNA_array[j].order > temp.order) {
                DNA_array[j + 1] = DNA_array[j];
                j--;
            }

            DNA_array[j + 1] = temp;
        }

        for (int i = 0; i < m; i++) {
            printf("%s\n", DNA_array[i].string);
        }
    }

    return 0;
}