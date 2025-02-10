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
    int size = l;
    int centerX = size / 2;
    int centerY = size / 2;
    int vertexX = 0;
    int vertexY = 0;

    while (size / 2 >= m) {
        solve(size, vertexX, vertexY, centerX, centerY);
        size /= 2;
        vertexX += size;
        vertexY += size;
        centerX += size / 2;
        centerY += size / 2;
    }
    
    return 0;
}
/*
    Score: Accepted 100

    Solution:
        Abandon the version 2 and 3 of the "automatic route search" idea,
        Instead, we made some minor changes to the version 1.

        Lile version 3,
        first cut it into many L-shaped pieces according to the size,
        with the cutout at the upper right corner (similar to type 1).

        But this time, use the first version of the thinking to deal with it.
        So it can handle like 16x16, 32x32 or other larger L-shaped.

    Example:
        Input:
            16 1

        Field:
            First (Imaginary):
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

                then it will be cut into 4 parts (or in other words, execute 4 times):

                part 1: (l = 16, m = 8)         | part 2: (l = 8, m = 4)          | part 3: (l = 4, m = 2)          | part 4: (l = 2, m = 1)          |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1         |                         1 1     |                             1   |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1         |                         1 1     |                             1 1 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1         |                         1 1 1 1 |                                 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1         |                         1 1 1 1 |                                 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1 1 1 1 1 |                                 |                                 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1 1 1 1 1 |                                 |                                 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1 1 1 1 1 |                                 |                                 |
                1 1 1 1 1 1 1 1                 |                 1 1 1 1 1 1 1 1 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |
                1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 |                                 |                                 |                                 |

            Then execute recursion for all blocks until the end:
                part 1: correct
                part 2: correct
                part 3: correct
                part 4: correct
*/