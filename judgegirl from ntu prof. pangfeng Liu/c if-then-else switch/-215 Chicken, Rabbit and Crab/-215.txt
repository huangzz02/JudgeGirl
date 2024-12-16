#include <stdio.h>

int main() {
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);

    if (s < 0 || f < 0 || t < 0) {
        printf("0\n");
        return 0;
    }

    int chi, rab, cra;
    
    // s=chi+rab+cra
    // f=chi*2+rab*4+cra*8
    // t=chi+rab
    
    cra = s - t;
    
    if ((f - cra * 8) % 2 != 0) { //important!!!
        printf("0\n");
        return 0;
    }
    
    f = (f - cra * 8) / 2;// f=chi+rab*2
    rab = f - t;
    chi = t - rab;
    
    if (chi < 0 || rab <0 || cra < 0) {
        printf("0\n");
    } else {
        printf("%d\n%d\n%d\n", chi, rab, cra);
    }
    
    return 0;
}