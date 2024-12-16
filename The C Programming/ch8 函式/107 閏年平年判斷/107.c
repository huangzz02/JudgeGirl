#include <stdio.h>
#include <stdlib.h>

//years.h
void years(int year);

//years.c
void years(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("%d是閏年\n", year);
    } else {
        printf("%d是平年\n", year);
    }
}

//main.c
int main(){
    int year;
    scanf("%d", &year);
    years(year);
    return 0;
}