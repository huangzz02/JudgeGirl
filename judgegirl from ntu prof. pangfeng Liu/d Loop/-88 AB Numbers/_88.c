#include <stdio.h>

int main() {
    char n[5], m[5];
    scanf("%s %s", n, m);
  
    int x = 0, y = 0;
    
    for (int i = 0; i <= 9; i++) {
        int count = 0;
        
        for (int j = 0; j < 4; j++) {
          
            if (n[j] == m[j]) {
                if (i == 0) {
                    x += 1;
                }
            } else if ((n[j] - '0') == i || (m[j] - '0') == i) {
                count += 1;
            }
          
        } if (count == 2) {
            y += 1;
        }
    }
  
    printf("%dA%dB\n", x, y);
    
    return 0;
} 