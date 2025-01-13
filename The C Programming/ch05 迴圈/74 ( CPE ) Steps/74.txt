#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);

        int distance = y - x;
        int count = 0;

        int z = (int)(ceil(sqrt(distance)));
        int step;
        if (z <= 1) {
            step = z == 0 ? 0 : 1;
        } else {
            step = distance > (z * (z-1)) ? (z*2)-1 : (z-1)*2;
        }
        
        printf("%d\n", step);
    }

    return 0;
}

// 1 1

// 2 11
// 3 111
// 4 121

// 5 1211
// 6 1221
// 7 12211
// 8 12221
// 9 12321

// 10 123211
// 11 123221
// 12 123321
// 13 1233211
// 14 1233221
// 15 1233321
// 16 1234321

// 1.check "perfect square"
// 2.check 2 different distance