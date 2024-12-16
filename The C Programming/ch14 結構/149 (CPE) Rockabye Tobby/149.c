#include <stdio.h>

struct data{
    char med[100];
    int time;
    int initial_time;
    int priority;
};

int main() {
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n, k;
        scanf("%d %d", &n, &k);

        struct data data_array[n];

        for (int i = 0; i < n; i++) {
            scanf("%s %d", data_array[i].med, &data_array[i].time);
            data_array[i].initial_time = data_array[i].time;
            data_array[i].priority = i;
        }

        for (int i = 1; i < n; i++) {
            struct data temp = data_array[i];
            int j = i - 1;
    
            while (j >= 0 && 
                   (data_array[j].time > temp.time || 
                   (data_array[j].time == temp.time && data_array[j].priority > temp.priority))) {
                data_array[j + 1] = data_array[j];
                j--;
            }
    
            data_array[j + 1] = temp;
        }

        while (k--) {
            printf("%d %s\n", data_array[0].time, data_array[0].med);
            data_array[0].time += data_array[0].initial_time;

            struct data temp = data_array[0];
            int i = 1;

            while (i < n && 
                   (data_array[i].time < temp.time || 
                   (data_array[i].time == temp.time && data_array[i].priority < temp.priority))) {
                data_array[i - 1] = data_array[i];
                i++;
            }

            data_array[i - 1] = temp;
        }
    }

    return 0;
}