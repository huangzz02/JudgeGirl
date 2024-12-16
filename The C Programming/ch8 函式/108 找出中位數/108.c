#include <stdio.h>

//mid.h
void mid(int a[5], int n);

//mid.c
void mid(int a[5], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Median = %d\n", a[2]);
}

//main.c
int main() {
  int a[5], i;
  for(i = 0; i < 5; i++)
    scanf("%d", &a[i]);
  mid(a, 5);
  return 0;
}