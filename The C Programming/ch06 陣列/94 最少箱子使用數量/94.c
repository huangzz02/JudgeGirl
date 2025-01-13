#include <stdio.h>

int main() {
    while (1) {
        int b1, b2, b3, b4, b5, b6;
        scanf("%d %d %d %d %d %d", &b1, &b2, &b3, &b4, &b5, &b6);
        
        if (b1 == 0 &&
            b2 == 0 &&
            b3 == 0 &&
            b4 == 0 &&
            b5 == 0 &&
            b6 == 0) {
            break;
        }
        
        int count = 0;
        
        count += b6; // b6 over
        
        for (int i = 0; i < b5; i++) {
            for (int j = 0; j < 11; j++) { // b1 in the gap
                if (b1 > 0) {
                    b1--;
                }
            }
            count++;
        } // b5 over
        
        int area = 36;
        
        for (int i = 0; i < b4; i++) {
            area = 20;
            for (int j = 0; j < 5; j++) { // b2 in the gap
                if (b2 > 0 && area >= 4) {
                    area -= 4;
                    b2--;
                }
            }
            for (int j = 0; j < area; j++) { // b1 in the gap
                if (b1 > 0) {
                    b1--;
                }
            }
            count++;
        } // b4 over
        
        int b3_box;
        if (b3 % 4 == 0) {
            b3_box = b3 / 4;
        } else {
            b3_box = (b3 / 4) + 1;
        }
        
        for (int i = 0; i < b3_box; i++) {
            area = 36;
            for (int j = 0; j < 4; j++) { // b3 first
                if (b3 > 0 && area >= 9) {
                    area -= 9;
                    b3--;
                }
            }
            
            int fit_b2;
            if (area == 27) {
                fit_b2 = 5;
            } else if (area == 18) {
                fit_b2 = 3;
            } else if (area == 9) {
                fit_b2 = 1;
            } else {
                fit_b2 = 0;
            }
            
            for (int j = 0; j < fit_b2; j++) { // b2 in the gap
                if (b2 > 0 && area >= 4) {
                    area -= 4;
                    b2--;
                }
            }
            for (int j = 0; j < area; j++) { // b1 in the gap
                if (b1 > 0) {
                    b1--;
                }
            }
            count++;
        } // b3 over

        int b2_box;
        if (b2 % 9 == 0) {
            b2_box = b2 / 9;
        } else {
            b2_box = (b2 / 9) + 1;
        }
        
        for (int i = 0; i < b2_box; i++) {
            area = 36;
            for (int j = 0; j < 9; j++) { // b2 first
                if (b2 > 0 && area >= 4) {
                    area -= 4;
                    b2--;
                }
            }
            for (int j = 0; j < area; j++) { // b1 in the gap
                if (b1 > 0) {
                    b1--;
                }
            }
            count++;
        } // b2 over

        if (b1 % 36 == 0) {
            count += b1 / 36;
        } else {
            count += (b1 / 36) + 1;
        } // b1 over
        
        
        printf("%d\n", count);
    }
    
    return 0;
}