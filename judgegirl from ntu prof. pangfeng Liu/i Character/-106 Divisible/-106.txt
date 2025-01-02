#include <stdio.h>
#include <stdlib.h>

int main() {
    while(1) {
        char str[1001];
        int ans[4] = {0}; // 2, 3, 5, 11
        scanf("%1000s", str);
        if (str[0] == '-' && str[1] == '1' && str[2] == '\0') break;

        int i;
        int sum = 0;
        int gap_11 = 0;
        for (i = 0; str[i] != '\0'; i++) {
            sum += str[i] - '0';
            if (i % 2 == 0) gap_11 += str[i] - '0';
            else gap_11 -= str[i] - '0';
        }

        if ((str[i - 1] - '0') % 2 == 0) ans[0] = 1;
        if (sum % 3 == 0) ans[1] = 1;
        if ((str[i - 1] - '0') % 5 == 0) ans[2] = 1;
        if (abs(gap_11) % 11 == 0) ans[3] = 1;
        
        for (int i = 0; i < 4; i++) {
            if (ans[i] == 1) printf("yes");
            else printf("no");
            
            if (i != 3) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}