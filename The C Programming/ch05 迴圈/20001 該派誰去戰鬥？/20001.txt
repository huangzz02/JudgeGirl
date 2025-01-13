#include <stdio.h>
 
int main() {
    int opp[5], a[5], b[5], c[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &opp[i]);
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d", &c[i]);
    }
    
    // blood, attack, defence, hit, dodge
 
    int a_r = 0, b_r = 0, c_r = 0;

    // a
    int opp_ori[5];
    for (int i = 0; i < 5; i++) {
        opp_ori[i] = opp[i];
    }

    while(1){
        if (a[3] < opp[4]) break;
        if (a[1] <= opp[2]) break;
 
        a_r++;
 
        if(a_r % 2 != 0) {
            opp[0] -= 2 * (a[1] - opp[2]);
        } else {
            opp[0] -= a[1] - opp[2];
        }
 
        if (opp[0] <= 0) break;
 
        if (opp[3] < a[4]) continue;
        if (opp[1] <= a[2]) continue;
 
        a[0] -= opp[1] - a[2];
 
        if (a[0] <= 0) {
            a_r = 0;
            break;
        }
    }

    // b 
    for (int i = 0; i < 5; i++) {
        opp[i] = opp_ori[i];
    }

    int count_b = 0;
    while(1){
        if (b[3] < opp[4]) break;
        if (b[1] <= opp[2]) break;
 
        b_r++;
 
        opp[0] -= b[1] - opp[2];
 
        if (opp[0] <= 0) break;
 
        if (opp[3] < b[4]) continue;
        if (opp[1] <= b[2]) continue;
 
        b[0] -= opp[1] - b[2];
 
        if (b[0] <= 0) {
            count_b++;
            if (count_b <= 3) {
                b[0] = 1;
            } else {
                b_r = 0;
                break;
            }
        }
    }

    // c
    for (int i = 0; i < 5; i++) {
        opp[i] = opp_ori[i];
    }

    while(1){
        if (c[3] < opp[4]) break;
 
        c_r++;
 
        if (c_r != 1 && c_r % 2 != 0) {
            c[1]++;
        }

        if (c[1] <= opp[2]) continue;
        opp[0] -= c[1] - opp[2];
 
        if (opp[0] <= 0) break;
 
        if (opp[3] < c[4]) continue;
        if (opp[1] <= c[2]) continue;
 
        c[0] -= opp[1] - c[2];
 
        if (c[0] <= 0) {
            c_r = 0;
            break;
        }
    }

    if (a_r == 0) a_r = 1e9;
    if (b_r == 0) b_r = 1e9;
    if (c_r == 0) c_r = 1e9;
 
    if (a_r < b_r && a_r < c_r) {
        printf("0 %d\n", a_r);
    } else if (b_r < c_r) {
        printf("1 %d\n", b_r);
    } else {
        printf("2 %d\n", c_r);
    }
 
    return 0;
}