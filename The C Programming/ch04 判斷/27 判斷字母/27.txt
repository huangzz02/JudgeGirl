#include <stdio.h>
#include <ctype.h>

int main(){
    
    char ipt[2];
    scanf("%s", ipt);
    
    char c = ipt[0];
    
    if (isalpha(c)) {
        if (c == 'A' || c == 'a') {
            printf("the first.\n");
        } else if (c == 'Z' || c == 'z') {
            printf("the last.\n");
        } else {
            c = toupper(c);
            int pre = c - 1;
            int nxt = c + 1;
            printf("%c%c\n", (char)pre, (char)nxt);
        }
    } else {
        printf("not English.\n");
    }
    
    return 0;
}