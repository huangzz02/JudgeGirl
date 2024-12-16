#include <stdio.h>

// fac.h
extern int moneyPerm(int K);

// fac.c
int moneyPerm(int K) {
    if (K < 0) return 0;       // 無效組合
    if (K == 0) return 0;      // 剛好匹配組合
    return 1 + moneyPerm(K - 5) + moneyPerm(K - 10);
}

// main.c
int main() {
    int money;
    scanf("%d", &money);
    printf("%d\n", moneyPerm(money));
    return 0;
}
