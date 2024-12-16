#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
 
typedef struct pair {
    int frequency;
    char charASCII;
} pair;
 
void print(pair* myData) {
    int i;
    for (i = 0; i < 95; i++)
        (myData[i].frequency == 0) ? printf("") : printf("%d %d\n", myData[i].charASCII, myData[i].frequency);
}
 
int main() {
    struct pair* myData = (struct pair*)malloc(95 * sizeof(struct pair));
    int i, len, flag = 0;
    char str[9999];
 
    while (gets(str) != NULL) {
        if (flag != 0) printf("\n");
        flag++;

        // 初始化 myData 的頻率為 0，並設置 ASCII 值
        for (i = 0; i < 95; i++) {
            myData[i].frequency = 0;
            myData[i].charASCII = i + 32; // ASCII 32~126
        }

        // 統計字元頻率
        len = strlen(str);
        for (i = 0; i < len; i++) {
            if (str[i] >= 32 && str[i] <= 126) {
                myData[str[i] - 32].frequency++;
            }
        }

        // 排序（按頻率由低到高，頻率相同則按 ASCII 值由大到小）
        for (i = 0; i < 94; i++) {
            for (int j = i + 1; j < 95; j++) {
                if (
                    myData[i].frequency > myData[j].frequency || 
                    (myData[i].frequency == myData[j].frequency && myData[i].charASCII < myData[j].charASCII)
                ) {
                    pair temp = myData[i];
                    myData[i] = myData[j];
                    myData[j] = temp;
                }
            }
        }

        print(myData);
    }

    free(myData);
    return 0;
}