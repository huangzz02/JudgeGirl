#include <stdio.h>

//count_ones.h
int count_ones(int dec_num);

//count_ones.c
int count_ones(int dec_num) {
    int s = 0;
    
    while (dec_num > 0) {
        if (dec_num % 2 == 1) s++;
        dec_num /= 2;
    }
    return s;
}

//main.c
int main() {
    int a, b;
 
    while(scanf("%d%d", &a, &b)) {
        int total_ones_num = 0;
        if (a == 0 && b == 0) break;
        for(int i = a;i <= b;i++) {
            total_ones_num += count_ones(i);
        }
        printf("%d\n", total_ones_num);
    }
 
    return 0;
}