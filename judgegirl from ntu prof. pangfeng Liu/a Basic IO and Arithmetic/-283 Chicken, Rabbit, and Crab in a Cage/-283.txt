#include <stdio.h>

int main() {
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);

    int chi, rab, cra;
    
    // s=chi+rab+cra
    // f=chi*2+rab*4+cra*8
    // t=chi+rab
    
    cra = s - t;
    f = (f - cra * 8) / 2;// f=chi+rab*2
    rab = f - t;
    chi = t - rab;
    
    printf("%d\n%d\n%d\n", chi, rab, cra);
    return 0;
}