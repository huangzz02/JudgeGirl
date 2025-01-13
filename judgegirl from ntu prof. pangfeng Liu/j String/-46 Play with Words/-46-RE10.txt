#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    int freq;
    int first_occurrence;
} CharInfo;

void count_frequency_and_occurrence(const char *data, CharInfo *char_info) {
    for (int i = 0; i < strlen(data); i++) {
        char c = data[i];
        if (char_info[c].freq == 0) {
            char_info[c].first_occurrence = i;
        }
        char_info[c].freq++;
    }
}

void insertion_sort(CharInfo *char_info, int size) {
    for (int i = 1; i < size; i++) {
        CharInfo key = char_info[i];
        int j = i - 1;
        
        while (j >= 0 && (char_info[j].freq < key.freq ||
                         (char_info[j].freq == key.freq && char_info[j].first_occurrence > key.first_occurrence))) {
            char_info[j + 1] = char_info[j];
            j--;
        }
        char_info[j + 1] = key;
    }
}

int main() {
    char input[100];
    char *data = malloc(100 * sizeof(char));
    data[0] = '\0'; // started from ""
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 1.insert left x (abcd -> xabcd)
        if (strncmp(input, "insert left", 11) == 0) {
            char x = input[12];
            memmove(data + 1, data, strlen(data) + 1);
            data[0] = x;
        }
        // 2.insert right x (abcd -> abcdx)
        else if (strncmp(input, "insert right", 12) == 0) {
            char x[2] = {input[13], '\0'};
            strcat(data, x);
        }
        // 3.insert k x (abc, k = 3 -> abxcd)
        else if (strncmp(input, "insert", 6) == 0) {
            int k;
            char x;
            sscanf(input, "insert %d %c", &k, &x);
            memmove(data + k, data + k - 1, strlen(data) - (k - 1) + 1); // prone to errors
            data[k - 1] = x;
        }
        // 4.delete left (abcd -> bcd)
        else if (strncmp(input, "delete left", 11) == 0) {
            memmove(data, data + 1, strlen(data));
        }
        // 5.delete right (abcd -> abc)
        else if (strncmp(input, "delete right", 12) == 0) {
            data[strlen(data) - 1] = '\0';
        }
        // 6.delete k (abcd, k = 3 -> abd)
        else if (strncmp(input, "delete", 6) == 0) {
            int k;
            sscanf(input, "delete %d", &k);
            memmove(data + k - 1, data + k, strlen(data) - k + 1); // prone to errors
        }
    }
    
    CharInfo char_info[256] = {0};
    for (int i = 0; i < 256; i++) {
        char_info[i].c = i;
    }

    count_frequency_and_occurrence(data, char_info);

    insertion_sort(char_info, 256); // arrange from large to small
    int max = char_info[0].freq;

    for (int i = 0; i < 256; i++) {
        if (char_info[i].freq == max) {
            printf("%c ", char_info[i].c);
        }
    }
    printf("%d\n", max);
    
    free(data);
    return 0;
}
/*
    The problem of this version is:
    1. Can't deal with no input case (line 85 causes error).
    2. Read the topic wrong.
       (The question is to find "find the maximum number of [consecutive] totals and output them in order of appearance",
        but I misread it as "find the maximum number of total [occurrences] and output them in order of appearance")
    3. When data is more than 100 characters, it will overflow because I forgot to use "realloc".
*/