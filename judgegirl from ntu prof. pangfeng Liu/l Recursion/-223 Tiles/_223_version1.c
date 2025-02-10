#include <stdio.h>

int findType(int vertexX, int vertexY, int centerX, int centerY) {
    if (vertexX < centerX && vertexY < centerY) return 1;
    else if (vertexX > centerX && vertexY < centerY) return 2;
    else if (vertexX > centerX && vertexY > centerY) return 3;
    else return 4;
}

void solve(int size, int vX, int vY, int cX, int cY) {
    if (size == 2) {
        printf("%d %d %d\n", findType(vX, vY, cX, cY), cX, cY);
        return;
    }

    int qtr = size / 4;
    int mid = size / 2;

    if (findType(vX, vY, cX, cY) == 1) {
        solve(mid, vX + qtr , vY + qtr , cX      , cY      );
        solve(mid, vX       , vY + size, cX - qtr, cY + qtr);
        solve(mid, vX       , vY       , cX - qtr, cY - qtr);
        solve(mid, vX + size, vY       , cX + qtr, cY - qtr);
    } else if (findType(vX, vY, cX, cY) == 2) {
        solve(mid, vX - qtr , vY + qtr , cX      , cY      );
        solve(mid, vX       , vY + size, cX + qtr, cY + qtr);
        solve(mid, vX       , vY       , cX + qtr, cY - qtr);
        solve(mid, vX - size, vY       , cX - qtr, cY - qtr);
    } else if (findType(vX, vY, cX, cY) == 3) {
        solve(mid, vX - qtr , vY - qtr , cX      , cY      );
        solve(mid, vX - size, vY       , cX - qtr, cY + qtr);
        solve(mid, vX       , vY       , cX + qtr, cY + qtr);
        solve(mid, vX       , vY - size, cX + qtr, cY - qtr);
    } else {
        solve(mid, vX + qtr , vY - qtr , cX      , cY      );
        solve(mid, vX + size, vY       , cX + qtr, cY + qtr);
        solve(mid, vX       , vY       , cX - qtr, cY + qtr);
        solve(mid, vX       , vY - size, cX - qtr, cY - qtr);
    }
}

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    int centerX = l - m;
    int centerY = l - m;

    solve(l, 0, 0, centerX, centerY);

    return 0;
}
/*
    Score: Wrong Answer 40

    Solution:
        Split into 4 parts until each part is 2x2,
        then print the type of the part and the center of the part.

    Example:
        Input:
            8 4

        Field: (Imaginary)
            First: (4x4 L-shape)
                B B B B
                B B B B
                B B A A
                B B A A
                C C A A A A D D
                C C A A A A D D
                C C C C D D D D
                C C C C D D D D

            Second: (2x2 L-shape)
                BC BC BB BB
                BC BA BA BB
                BD BA AB AB
                BD BD AB AA
                CB CB AC AA AA AD DB DB
                CB CA AC AC AD AD DA DB
                CC CA CA CD DD DA DA DC
                CC CC CD CD DD DD DC DC

    Problem:
        The program crashes if the second value entered is not half of the first.

        ex:
            input: 8 4 -> correct
            input: 8 2 -> crash
*/