#include <stdio.h>

//_A_B_C.h
void _A_B_C(int num1, int num2);

//_A_B_C.c
void _A_B_C(int num1, int num2) {
    int a = 0, b = 0, c = 0;

    char x[5], y[5];
    sprintf(x, "%d", num1);
    sprintf(y, "%d", num2);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (x[i] == y[j] && i == j) {
                a++;
                break;
            } else if (x[i] == y[j]) {
                b++;
                break;
            }
        }
    }

    c = (4-a-b) * 2;

    printf("%dA%dB%dC", a, b, c);
}

//main.c
int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    _A_B_C(num1, num2);
 
    return 0;
}