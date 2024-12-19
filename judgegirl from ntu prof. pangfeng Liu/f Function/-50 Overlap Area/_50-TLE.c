#include <stdio.h>

int main() {
    int Ax1, Ay1, Ax2, Ay2;
    int Bx1, By1, Bx2, By2;
    int Cx1, Cy1, Cx2, Cy2;

    scanf("%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);
    scanf("%d %d %d %d", &Bx1, &By1, &Bx2, &By2);
    scanf("%d %d %d %d", &Cx1, &Cy1, &Cx2, &Cy2);

    int s = 0;
    s += (Ax2 - Ax1) * (Ay2 - Ay1); // +A
    s += (Bx2 - Bx1) * (By2 - By1); // +B
    s += (Cx2 - Cx1) * (Cy2 - Cy1); // +C
    
    /*
        Search one of the rectangles.
        When the coordinate point is in another rectangle,
        deduct the 1 * 1 grid in the upper right corner of the point.
    */

    // -AB
    for (int i = Ax1; i < Ax2; i++) {
        for (int j = Ay1; j < Ay2; j++) {
            if (i >= Bx1 && i < Bx2 && j >= By1 && j < By2) {
                s -= 1;
            }
        }
    }

    // -BC
    for (int i = Bx1; i < Bx2; i++) {
        for (int j = By1; j < By2; j++) {
            if (i >= Cx1 && i < Cx2 && j >= Cy1 && j < Cy2) {
                s -= 1;
            }
        }
    }

    // -AC
    for (int i = Cx1; i < Cx2; i++) {
        for (int j = Cy1; j < Cy2; j++) {
            if (i >= Ax1 && i < Ax2 && j >= Ay1 && j < Ay2) {
                s -= 1;
            }
        }
    }

    // +ABC
    for (int i = Ax1; i < Ax2; i++) {
        for (int j = Ay1; j < Ay2; j++) {
            if ((i >= Bx1 && i < Bx2 && j >= By1 && j < By2) &&
                (i >= Cx1 && i < Cx2 && j >= Cy1 && j < Cy2)) {
                s += 1;
            }
        }
    }

    printf("%d\n", s);
    
    return 0;
}