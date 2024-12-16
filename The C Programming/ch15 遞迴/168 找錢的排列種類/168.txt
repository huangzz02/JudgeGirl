#include <stdio.h>

// moneyPerm.h
extern int moneyPerm(int K);

// moneyPerm.c
int moneyPerm(int K){
    if (K < 0) return 0;
    else if (K == 0) return 1;
    else return moneyPerm(K - 1) + moneyPerm(K - 5) + moneyPerm(K - 10);
}

// main.c
int main(){
    int money;
    scanf("%d", &money);
    printf("%d", moneyPerm(money));
    return 0;
}