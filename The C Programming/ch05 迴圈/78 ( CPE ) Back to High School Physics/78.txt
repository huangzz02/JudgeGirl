#include <stdio.h>

int main() {
    int v, t;
    while (scanf("%d %d", &v, &t) != EOF) {
        // v0 + at = v

        // d = ((v0 + (v0 + a*2t)) * 2t ) / 2
        //   = 2t * (v0 + at)
        //   = 2t * (v0 + (v - v0))
        //   = 2tv
        printf("%d\n", 2 * v * t);
    }
    return 0;
}