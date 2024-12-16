#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int ax, ay, bx, by, cx, cy, dx, dy;
        scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
        
        int ABx, ABy, BCx, BCy, CDx, CDy, DAx, DAy;
        int ABxBC, BCxCD, CDxDA, DAxAB;
        
        while (1) {
            ABx = bx - ax;
            ABy = by - ay;
            BCx = cx - bx;
            BCy = cy - by;
            CDx = dx - cx;
            CDy = dy - cy;
            DAx = ax - dx;
            DAy = ay - dy;
        
            ABxBC = ABx * BCy - ABy * BCx;
            BCxCD = BCx * CDy - BCy * CDx;
            CDxDA = CDx * DAy - CDy * DAx;
            DAxAB = DAx * ABy - DAy * ABx;
        
            if (ABxBC >= 0 && BCxCD >= 0 && CDxDA >= 0 && DAxAB >= 0) {
                break;
            }
            int tempx, tempy;
            if (ABxBC < 0) {
                tempx = bx; tempy = by;
                bx = cx; by = cy;
                cx = tempx; cy = tempy;
            } else if (BCxCD < 0) {
                tempx = cx; tempy = cy;
                cx = dx; cy = dy;
                dx = tempx; dy = tempy;
            } else if (CDxDA < 0) {
                tempx = dx; tempy = dy;
                dx = ax; dy = ay;
                ax = tempx; ay = tempy;
            } else if (DAxAB < 0) {
                tempx = ax; tempy = ay;
                ax = cx; ay = cy;
                cx = tempx; cy = tempy;
            }
        }
        //A, B, C, D are already arranged in counterclockwise arder
        
        double AB, BC, CD, DA;
        AB = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
        BC = sqrt((cx - bx) * (cx - bx) + (cy - by) * (cy - by));
        CD = sqrt((dx - cx) * (dx - cx) + (dy - cy) * (dy - cy));
        DA = sqrt((ax - dx) * (ax - dx) + (ay - dy) * (ay - dy));
        
        int equal = fabs(AB - BC) < 1e-6 &&
                    fabs(BC - CD) < 1e-6 &&
                    fabs(CD - DA) < 1e-6 &&
                    fabs(DA - AB) < 1e-6;
        
        double AC, BD;
        AC = sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));
        BD = sqrt((dx - bx) * (dx - bx) + (dy - by) * (dy - by));
        
        int right = fabs(AB * AB + BC * BC - AC * AC) < 1e-6 &&
                    fabs(BC * BC + CD * CD - BD * BD) < 1e-6 &&
                    fabs(CD * CD + DA * DA - AC * AC) < 1e-6 &&
                    fabs(DA * DA + AB * AB - BD * BD) < 1e-6;
        
        if (equal && right) {
            printf("square\n");
        } else if (equal) {
            printf("diamond\n");
        } else if (right) {
            printf("rectangle\n");
        } else {
            printf("other\n");
        }
    }
    
    return 0;
}