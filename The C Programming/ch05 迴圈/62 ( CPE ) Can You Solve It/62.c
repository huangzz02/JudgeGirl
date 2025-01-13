#include <stdio.h>

long long step (int x1, int y1, int x2, int y2) {
    long long count = 0;
    
    int sum1 = x1 + y1;
    int sum2 = x2 + y2;
    
    for (int i = sum1 + 1; i < sum2; i++) {
        count += (i + 1);
    }
    
    if (sum1 != sum2) {
        while (y1 > 0) {
            y1--;
            count++;
        }
        
        count += (x2 + 1);
    } else {
        while (y1 != y2) {
            y1--;
            count++;
        }
    }
    
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        printf("Case %d: %lld\n", i + 1, step(x1, y1, x2, y2));
    }

    return 0;
}