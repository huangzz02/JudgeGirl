#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//len.h
void len(char *arr);

//len.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void len(char *arr) {
    int a = strlen(arr);
    printf("%d\n", a);
}

//main.c
int main()
{
    char arr[60];
    scanf("%s",arr);
    len(arr);
}