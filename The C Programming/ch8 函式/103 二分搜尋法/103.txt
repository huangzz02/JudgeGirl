#include <stdio.h>

//binarysearch.h
int binarysearch(int data[], int search, int n);

//binarysearch.c
int binarysearch(int data[], int search, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (data[mid] == search) return mid;
        else if (data[mid] < search) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

//main.c
int main() {
    int search, ans;
    int data[] = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
 
    scanf("%d", &search);
    ans = binarysearch(data, search, sizeof(data) / sizeof(int));
    if (ans < 0) {
        printf("找不到 %d\n", search);
    }
    else {
        printf("在第 %d 筆資料找到 %d\n", ans + 1, search);
    }
 
    return 0;
}