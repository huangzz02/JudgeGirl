#include <stdio.h>

int main() {
    int gifts, friends, class[101] = {0}, get_gift = 0;
    scanf("%d%d", &gifts, &friends);

    while (gifts--) {
        int input;
        scanf("%d", &input);
        class[input]++;
    }

    for (int i = 0; i < 101; i++) {
        get_gift += class[i] / friends;
    }

    printf("%d\n", get_gift);

    return 0;
}