#include <stdio.h>

//ID_Check.h
void ID_Check(char ID[]);

//ID_Check.c
void ID_Check(char ID[]) {
    int temp;
    switch(ID[0]) {
        case 'A': temp = 10; break;
        case 'B': temp = 11; break;
        case 'C': temp = 12; break;
        case 'D': temp = 13; break;
        case 'E': temp = 14; break;
        case 'F': temp = 15; break;
        case 'G': temp = 16; break;
        case 'H': temp = 17; break;
        case 'I': temp = 34; break;
        case 'J': temp = 18; break;
        case 'K': temp = 19; break;
        case 'L': temp = 20; break;
        case 'M': temp = 21; break;
        case 'N': temp = 22; break;
        case 'O': temp = 35; break;
        case 'P': temp = 23; break;
        case 'Q': temp = 24; break;
        case 'R': temp = 25; break;
        case 'S': temp = 26; break;
        case 'T': temp = 27; break;
        case 'U': temp = 28; break;
        case 'V': temp = 29; break;
        case 'W': temp = 32; break;
        case 'X': temp = 30; break;
        case 'Y': temp = 31; break;
        case 'Z': temp = 33; break;
    }

    int s = 0;
    s += temp/10 + temp%10 * 9;

    int count = 8;
    for (int i = 1; i <= 8; i++) {
        s += (ID[i] - '0') * count;
        count--;
    }
    s += ID[9] - '0';
    
    if (s % 10 == 0) printf("real\n");
    else printf("fake\n");
}

//main.c
int main() {
    char ID[100];
    while (scanf("%s", ID) != EOF) {
        ID_Check(ID);
    }
    return 0;
}