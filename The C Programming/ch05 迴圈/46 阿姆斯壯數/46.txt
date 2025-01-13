#include <stdio.h>
#include <string.h>

int main(){
    int a = 1, b = 1;
    while (1) {
        scanf("%d %d", &a, &b);
        
        if (a == 0 && b == 0) {
            break;
        }
        
        int found = 0;
        for (int i = a; i <= b; i++) {
            char ams[20];
            sprintf(ams, "%d", i);
            
            int sum = 0;
            for (int j = 0; j < strlen(ams); j++) {
                int k = ams[j] - '0';
                sum += k * k * k;
            }
            
            if (sum == i) {
                printf("有\n");
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("無\n");
        }
    }
    
    return 0;
}