#include <stdio.h>
#include <stdlib.h>
 
typedef struct List{
    int num;
    int mod;
    int Even_Odd; // odd == 1, even == 0
}List;

int main() {
    int times = 20;
    while (times--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d %d\n", n, m);

        if (n == 0 || m == 0) break;
    
        List* myData = (List*)malloc(n * sizeof(List));
    
        for (int i = 0; i < n; i++) {
            scanf("%d", &myData[i].num);
            myData[i].mod = myData[i].num % m;
            myData[i].Even_Odd = abs(myData[i].num) % 2;
        }
    
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (
                    myData[i].mod > myData[j].mod || 
                    (myData[i].mod == myData[j].mod && myData[i].Even_Odd < myData[j].Even_Odd) ||
                    (myData[i].mod == myData[j].mod && myData[i].Even_Odd == myData[j].Even_Odd && myData[i].num < myData[j].num && myData[i].Even_Odd == 1) ||
                    (myData[i].mod == myData[j].mod && myData[i].Even_Odd == myData[j].Even_Odd && myData[i].num > myData[j].num && myData[i].Even_Odd == 0)
                ) {
                    List temp = myData[i];
                    myData[i] = myData[j];
                    myData[j] = temp;
                }
            }
        }
    
        for (int i = 0; i < n; i++) {
            printf("%d\n", myData[i].num);
        }
    
        free(myData);
    }

    return 0;
}