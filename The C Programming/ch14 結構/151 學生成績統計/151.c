#include <stdio.h>
#include <string.h>

struct Student {
    char studentName[20];
    int score;
};

int main() {
    struct Student s;
    int cases = 3;

    int sum = 0, highest = 0;
    char max[20];
    while (cases--) {
        scanf("%s %d", s.studentName, &s.score);
        sum += s.score;
        if (s.score > highest) {
            highest = s.score;
            strcpy(max, s.studentName);
        }
    }

    printf("avg = %d\n", sum / 3);
    printf("max = %s\n", max);

    return 0;
}