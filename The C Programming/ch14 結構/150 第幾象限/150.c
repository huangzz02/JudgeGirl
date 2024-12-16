#include <stdio.h>

typedef struct point_t point_t;
struct point_t {
    double x;
    double y;
};

int main() {
    point_t p;
    scanf("%lf %lf", &p.x, &p.y);

    if (p.x > 0 && p.y > 0) {
        printf("第一象限\n");
    } else if (p.x < 0 && p.y > 0) {
        printf("第二象限\n");
    } else if (p.x < 0 && p.y < 0) {
        printf("第三象限\n");
    } else {
        printf("第四象限\n");
    }

    return 0;
}