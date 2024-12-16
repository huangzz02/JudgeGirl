#include <stdio.h>
#include <string.h>

void reverse(char *str) { 
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


int main(){
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);
        
        if (m == 0 && n == 0) {
            break;
        }
        
        if (m > n) { 
            int temp = m;
            m = n;
            n = temp;
        }
        // make sure m < n
        
        char ch_m[20], ch_n[20];
        sprintf(ch_m, "%d", m);
        sprintf(ch_n, "%d", n);
        //transfer into "char[]"
        
        
        reverse(ch_m);
        reverse(ch_n);
        
        
        int len_m = strlen(ch_m);
        int len_n = strlen(ch_n);
        
        int count = 0;
        int carry = 0;
        
        for (int i = 0; i < len_n; i++) {
            
            int digit_m = (i < len_m) ? ch_m[i] - '0' : 0;
            int digit_n = (i < len_n) ? ch_n[i] - '0' : 0;
            
            int sum = digit_m + digit_n + carry;
            
            if (sum >= 10) {
                count += 1;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        
        if (count == 0) {
            printf("No carry operation.\n");
        } else if (count == 1){
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", count);
        }
    }
    
    return 0;
}