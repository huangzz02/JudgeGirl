#include <stdio.h>

// lcs.h
int lcs(int*, int*, int, int);
void int_to_array(int*, int, int);

// lcs.c
int lcs(int* text1, int* text2, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (text1[m - 1] == text2[n - 1]) {
        return 1 + lcs(text1, text2, m - 1, n - 1);
    } else {
        int option1 = lcs(text1, text2, m - 1, n);
        int option2 = lcs(text1, text2, m, n - 1);
        return option1 > option2 ? option1 : option2;
    }
}
void int_to_array(int* array1, int value, int index) {
    for (int i = index - 1; i >= 0; i--) {
        array1[i] = value % 10;
        value /= 10;
    }
}

// main.c
int main() {
    int ans = 0;
    int text1[100] = { 0 };
    int text2[100] = { 0 };
    int t1, t2, m, n;
 
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &t1);
    scanf("%d", &t2);
 
    int_to_array(text1, t1, m);
    int_to_array(text2, t2, n);
    ans = lcs(text1, text2, m, n);
    printf("%d", ans);
    return 0;
}