#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int n;
        scanf("%d", &n);
        
        int drink = n; // 一開始可以喝 n 罐
        int bottles = n; // 先喝完所有汽水後有 n 個空瓶
        
        while (bottles >= 3) {
            int new_drinks = bottles / 3; // 用空瓶換新汽水
            drink += new_drinks; // 累計喝過的汽水數
            bottles = bottles % 3 + new_drinks; // 剩下的空瓶加上新喝的汽水留下的空瓶
        }
        
        // 如果還有兩個空瓶，可以借一個空瓶換最後一罐汽水
        if (bottles == 2) {
            drink++;
        }
        
        printf("%d\n", drink);
    }

    return 0;
}