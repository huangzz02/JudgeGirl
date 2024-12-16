#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    int money = 1000, count = 0;
  
    if (a < 0) {
        printf("error\n");
    } else {
        while (money > 0) {
            if (a / money > 0){
                printf("%d: %d\n", money, a/money);
                a = a % money;
            }
    
            if (count % 2 == 0) {
                money /= 2;
            } else {
                money /= 5;
            }
            count++;
        }
    }

    return 0;
}