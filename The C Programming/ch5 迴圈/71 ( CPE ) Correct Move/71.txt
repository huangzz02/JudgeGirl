#include <stdio.h>

int illegal_move (int king, int queen, int new_queen) {
    int ki = king / 8;
    int kj = king % 8;
    
    int qi = queen / 8;
    int qj = queen % 8;
    
    int nqi = new_queen / 8;
    int nqj = new_queen % 8;
    
    if (!(qi == nqi && qj == nqj)) { // not the same spot
        if (((qi == nqi) && (qi != ki)) ||
            ((qj == nqj) && (qj != kj))   ) { // not in the same line
            return 0;
        } else {
            if (qi == nqi) {
                if ((qj < kj && nqj < kj) ||
                    (qj > kj && nqj > kj)   ) {
                    return 0;
                }
            } else if (qj == nqj) {
                if ((qi < ki && nqi < ki) ||
                    (qi > ki && nqi > ki)   ) {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

int stop (int king, int new_queen) {
    if ((king == 0  && new_queen ==  9) ||
        (king == 7  && new_queen == 14) ||
        (king == 56 && new_queen == 49) ||
        (king == 63 && new_queen == 54)   ) {
        return 1;
    }
    
    return 0;
}

int move_not_allowed (int king, int new_queen) {
    int i = king / 8;
    int j = king % 8;
    
    int detect = 0;
    
    if (i > 0) {
        if ((king - 8) == new_queen) {
            detect = 1;
        }
    }
    if (i < 7) {
        if ((king + 8) == new_queen) {
            detect = 1;
        }
    }
    if (j > 0) {
        if ((king - 1) == new_queen) {
            detect = 1;
        }
    }
    if (i < 7) {
        if ((king + 1) == new_queen) {
            detect = 1;
        }
    }
    
    return detect;
}

int main() {
    int king, queen, new_queen;
    while (scanf("%d %d %d", &king, &queen, &new_queen) == 3) {
        
        //  0  1  2  3  4  5  6  7
        //  8  9 10 11 12 13 14 15
        // 16 17 18 19 20 21 22 23
        // 24 25 26 27 28 29 30 31
        // 32 33 34 35 36 37 38 39
        // 40 41 42 43 44 45 46 47
        // 48 49 50 51 52 53 54 55
        // 56 57 58 59 60 61 62 63
        
        if (king == queen) {
            printf("Illegal state\n");
        } else if (illegal_move(king, queen, new_queen)) {
            printf("Illegal move\n");
        } else if (stop(king, new_queen)) {
            printf("Stop\n");
        } else if (move_not_allowed(king, new_queen)) {
            printf("Move not allowed\n");
        } else {
            printf("Continue\n");
        }

    }
    
    return 0;
}