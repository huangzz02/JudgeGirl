#include <stdio.h>

int main() {
    unsigned int a, b;
    
    while (1) {
        scanf("%u %u", &a, &b);  // 讀取兩個正整數
        
        if (a == 0 && b == 0) {
            break;  // 若兩數皆為 0，結束輸入
        }

        int carry_count = 0;  // 進位次數計數器
        int carry = 0;  // 用來追蹤是否有進位的變數

        while (a > 0 || b > 0) {
            int digit_a = a % 10;  // 取得 a 的最後一位
            int digit_b = b % 10;  // 取得 b 的最後一位

            if (digit_a + digit_b + carry >= 10) {
                carry = 1;  // 發生進位
                carry_count++;  // 進位次數加1
            } else {
                carry = 0;  // 沒有進位
            }

            a /= 10;  // 去掉 a 的最後一位
            b /= 10;  // 去掉 b 的最後一位
        }

        // 輸出結果
        if (carry_count == 0) {
            printf("No carry operation.\n");
        } else {
            printf("%d carry operation%s.\n", carry_count, carry_count > 1 ? "s" : "");
        }
    }

    return 0;
}
