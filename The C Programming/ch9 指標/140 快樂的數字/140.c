#include <stdio.h>
#include <stdbool.h>

// Happynumber.h
int next_n(int);
bool contains(int*, int, int);
bool isHappy(int);

// Happynumber.c
int next_n(int n) {
    int s = 0;
    while(n > 0) {
        s += (n % 10) * (n % 10);
        n /= 10;
    }
    return s;
}
 
bool contains(int* history, int size, int n) {
    for (int i = 0; i < size; i++) {
        if (history[i] == n) {
            return true;
        }
    }
    return false;
}
 
bool isHappy(int n) {
    int history[1000];
    int size = 1;
    
    while (1) {
        if (n == 1) {
            return true;
        }
        if (contains(history, size, n)) {
            return false;
        }

        history[size++] = n;
        n = next_n(n);
    }
}

// main.c
int main() {
    int n;
    scanf("%d", &n);
    if (isHappy(n)) {
        printf("true");
    }
    else {
        printf("false");
    }
    return 0;
}