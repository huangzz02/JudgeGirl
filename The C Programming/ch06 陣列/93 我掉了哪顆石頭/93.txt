#include <stdio.h>

int main() {
    int num;
    int arr[100];
    int count = 0;
    int biggest = 1;
    
    while (scanf("%d", &num) == 1) {
        arr[count] = num;
        count++;
        if (num > biggest) {
            biggest = num;
        }
    }
    
    int check = 0;
    int ans;
    int found = 0;
    
    for (int i = 1; i <= biggest; i++) {
        check = 0;
        
        for (int j = 0; j < count; j++) {
            if (arr[j] == i) {
                check++;
            }
        }
        
        if (check == 2) {
            ans = i;
            found = 1;
            break;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}