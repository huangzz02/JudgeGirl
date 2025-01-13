#include <stdio.h>

int main() {
    int age;
    float height;
    scanf("%d %f",&age,&height);
    printf("Your age is: %d\nYour height is: %.5fm\n", age, height);
    return 0;
}