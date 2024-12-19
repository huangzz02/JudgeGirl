#include <stdio.h>

// 計算兩個矩形的交集面積
int getIntersectionArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int ix1 = x1 > x3 ? x1 : x3; // 左邊界取最大值
    int iy1 = y1 > y3 ? y1 : y3; // 上邊界取最大值
    int ix2 = x2 < x4 ? x2 : x4; // 右邊界取最小值
    int iy2 = y2 < y4 ? y2 : y4; // 下邊界取最小值

    if (ix1 < ix2 && iy1 < iy2) { // 有交集
        return (ix2 - ix1) * (iy2 - iy1);
    }
    return 0; // 無交集
}

int main() {
    int Ax1, Ay1, Ax2, Ay2;
    int Bx1, By1, Bx2, By2;
    int Cx1, Cy1, Cx2, Cy2;

    // 輸入三個矩形的座標
    scanf("%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);
    scanf("%d %d %d %d", &Bx1, &By1, &Bx2, &By2);
    scanf("%d %d %d %d", &Cx1, &Cy1, &Cx2, &Cy2);

    // 計算各個矩形的面積
    int areaA = (Ax2 - Ax1) * (Ay2 - Ay1);
    int areaB = (Bx2 - Bx1) * (By2 - By1);
    int areaC = (Cx2 - Cx1) * (Cy2 - Cy1);

    // 計算兩兩交集的面積
    int areaAB = getIntersectionArea(Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2);
    int areaBC = getIntersectionArea(Bx1, By1, Bx2, By2, Cx1, Cy1, Cx2, Cy2);
    int areaAC = getIntersectionArea(Ax1, Ay1, Ax2, Ay2, Cx1, Cy1, Cx2, Cy2);

    // 計算三個矩形的交集面積
    int ix1 = Ax1 > Bx1 ? (Ax1 > Cx1 ? Ax1 : Cx1) : (Bx1 > Cx1 ? Bx1 : Cx1); // 三個左邊界取最大值
    int iy1 = Ay1 > By1 ? (Ay1 > Cy1 ? Ay1 : Cy1) : (By1 > Cy1 ? By1 : Cy1); // 三個上邊界取最大值
    int ix2 = Ax2 < Bx2 ? (Ax2 < Cx2 ? Ax2 : Cx2) : (Bx2 < Cx2 ? Bx2 : Cx2); // 三個右邊界取最小值
    int iy2 = Ay2 < By2 ? (Ay2 < Cy2 ? Ay2 : Cy2) : (By2 < Cy2 ? By2 : Cy2); // 三個下邊界取最小值

    int areaABC = 0;
    if (ix1 < ix2 && iy1 < iy2) { // 檢查是否有交集
        areaABC = (ix2 - ix1) * (iy2 - iy1);
    }

    // 使用包含-排除原則計算聯集面積
    int totalArea = areaA + areaB + areaC - areaAB - areaBC - areaAC + areaABC;

    printf("%d\n", totalArea);

    return 0;
}
