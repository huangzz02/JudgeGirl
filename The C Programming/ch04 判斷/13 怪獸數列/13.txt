#include <stdio.h>
#include <string.h>

int main() {
    char a[10];
    scanf("%s", a);

    int l = strlen(a);
    char tem[10] = "";
  
    while (l > 0) {
        int t = a[0] - '0', k = 0, count = 0;
    
        for (int i = 0; i < l; i++) {
            if (a[i] - '0' != t) { 
                tem[k++] = a[i];
            } else {
                count += 1;
            }
        }
        tem[k] = '\0';
    
        printf("%d%d", count, t);

        l = strlen(tem);
        strcpy(a, tem);
    
        tem[0] = '\0';
    }
  
    return 0;
}