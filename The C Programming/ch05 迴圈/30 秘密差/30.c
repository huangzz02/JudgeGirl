#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char n[100];
    scanf("%s", n);
    
    int odd = 0, even = 0;
    for (int i = strlen(n) - 1; i >= 0; i--) {
        if (i % 2 == 0) { //odd, ex : n[0], n[2]
            odd += n[i] - '0';
        } else { //even, ex : n[1], n[3]
            even += n[i] - '0';
        }
    }
    printf("%.0f\n", fabs(odd - even));
    
    return 0;
}