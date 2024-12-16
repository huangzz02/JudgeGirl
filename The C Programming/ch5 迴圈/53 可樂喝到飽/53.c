#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int n;
        scanf("%d", &n);
        
        int drink = 0, rent = 0;
        drink = n; //先喝成空瓶
        while (n > 1) {
            if (n % 3 != 0) { //要借瓶子
                rent = 3 - (n % 3); //看差幾瓶要借
                n += rent; //借 0 ~ 2 罐
                
            } else { //不用借瓶子
                n /= 3; //換
                drink += n; //先喝成空瓶
            
                if (n < rent) {
                    drink -= n; //剛剛喝的不算
                    n = n * 3 - rent; //先加回來
                    int temp = n % 3; //temp 是不能整除的空瓶
                    n /= 3; //換 (利用 int 特性直接除)
                    drink += n; //先喝成空瓶
                    n += temp; //把不能整除的空瓶加回來
                } else {
                    n -= rent; //還瓶子
                    rent = 0; //下一輪是新的 借的歸零
                }
            }
        }
        printf("%d\n", drink);
    }

    return 0;
}