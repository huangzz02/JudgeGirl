#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    switch (a) {
        case 7:
            printf("該吃早餐囉\n");
            break;
        case 12:
            printf("該吃午餐囉\n");
            break;
        case 17:
            printf("該吃晚餐囉\n");
            break;
        default:
            printf("現在不能吃東西，會胖喔!\n");
            break;
    }

    return 0;
}