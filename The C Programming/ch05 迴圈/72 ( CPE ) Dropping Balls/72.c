#include <stdio.h>

void value_range (int length, int arr[]) {
    for (int i = 0; i < length; i++) {
        arr[i] = length + i;
    }
}

void reorder_arr (int arr[], int new_arr[], int length, int d) {
    for (int i = 0; i < length; i++) {
        int ori_i = i;
        int digit = arr[i];
        
        int len_binary = d - 1;
        int arr_binary[len_binary];
        
        for (int j = 0; j < len_binary; j++) {
            arr_binary[j] = i % 2;
            i /= 2;
        }// ex: i = 6 -> {0, 1, 1) (reversed binary digit)
        
        // i = 0
        for (int j = 0; j < len_binary; j++) {
            i += arr_binary[j] * (1 << ((len_binary - 1) - j));
        } // ex: {0, 1, 1) -> 3 (transfer into decimal)
        
        new_arr[i] = digit;
        
        i = ori_i;
    }
}

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int d, I;
        scanf("%d %d", &d, &I);
        
        int length = 1 << (d - 1);
        int arr[length];
        
        value_range(length, arr);
        
        int new_arr[length];
        
        reorder_arr(arr, new_arr, length, d);
        
        printf("%d\n", new_arr[I - 1]);
    }

    int out;
    scanf("%d", &out);

    if (out == -1) {
        return 0;
    }

}