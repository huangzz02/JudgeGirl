#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, d, e, f, g;
    scanf("%d\n%d\n%d\n%d\n%d\n%d\n%d", &a, &b, &c, &d, &e, &f, &g);
    
    //transform into "improper fraction"
    int u1, d1, u2, d2;
    if (a < 0) {
        u1 = -(abs(a) * c + b);
    } else {
        u1 = abs(a) * c + b;
    }
    if (e < 0) {
        u2 = -(abs(e) * g + f);
    } else {
        u2 = abs(e) * g + f;
    }
    d1 = c;
    d2 = g;
    
    //combine two fractions
    int ansu, ansd;
    if (d == 0) {
        ansu = u1 * d2 + u2 * d1;
        ansd = d1 * d2;
    } else if (d == 1) {
        ansu = u1 * d2 - u2 * d1;
        ansd = d1 * d2;
    } else if (d == 2) {
        ansu = u1 * u2;
        ansd = d1 * d2;
    } else if (d == 3) {
        ansu = u1 * d2;
        ansd = d1 * u2;
    }
    
    //ensure "ansu" != 0 (h = 0, i = 0, j = 1)
    if (ansu == 0) {
        printf("0\n0\n1\n");
        return 0;
    }
    
    //ensure "ansd" is positive
    if ((ansu >= 0 && ansd < 0)||(ansu < 0 && ansd < 0)) {
        ansu = -ansu;
        ansd = -ansd;
    }
    
    //search the "highest common factor" of the fraction's numerator and denominator
    int fac = 1, k;
    if (abs(ansu) > ansd) {
        k = ansd;
    } else {
        k = abs(ansu);
    }
    for (int i = 1; i < k + 1; i++) {
        if (abs(ansu) % i == 0 && ansd % i == 0) {
            fac = i;
        }
    }
    
    //simplify
    ansu /= fac;
    ansd /= fac;
    
    //transform into "mixed fraction"
    int h, i, j;
    if (ansu > 0) {
        h = ansu / ansd;
        i = ansu % ansd;
        j = ansd;
    } else {
        h = -(abs(ansu) / ansd);
        i = abs(ansu) % ansd;
        j = ansd;
    }
    
    printf("%d\n%d\n%d\n", h, i, j);

    return 0;
}