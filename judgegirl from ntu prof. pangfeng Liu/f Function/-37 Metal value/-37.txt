#include <stdio.h>

// value.h
int value(int type, int width, int height, int length);

// value.c
int value(int type, int width, int height, int length) {
    int price;
    if (type == 79) price = 30; //. gold
    else if (type == 47) price = 10; // silver
    else if (type == 29) price = 4; // copper
    else if (type == 82) price = 5; // lead
    else if (type == 26) price = 3; // iron
    else if (type == 22) price = 9; // titanium
    else return -1;

    if (width <= 0 || height <= 0 || length <= 0) return -2;
    
    int tmpA = width, tmpB = height, tmpC = length;
    while (tmpB != 0) {
        int tmp = tmpB;
        tmpB = tmpA % tmpB;
        tmpA = tmp;
    }
    while (tmpC != 0) {
        int tmp = tmpC;
        tmpC = tmpA % tmpC;
        tmpA = tmp;
    }
    int max = tmpA;

    int pieces = (width / max) * (height / max) * (length / max);
    int volume = max * max * max;
    return (volume * volume) * price * pieces;
}

// main.c
int main() {
    int type, w, h, l;
    scanf("%d %d %d %d", &type, &w, &h, &l);
    printf("%d\n", value(type, w, h, l));
    return 0;
}