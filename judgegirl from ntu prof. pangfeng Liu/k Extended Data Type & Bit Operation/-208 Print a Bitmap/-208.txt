#include <stdio.h>

void dec_to_bin (unsigned int dec, int *bin) {
    int index = 0;
    while (dec > 0) {
        bin[index] = dec % 2;
        dec /= 2;
        index++;
    }
    for (int i = index; i < 32; i++) {
        bin[i] = 0;
    }

    for (int i = 0; i < 16; i++) { // reverse order
        int temp = bin[i];
        bin[i] = bin[31 - i];
        bin[31 - i] = temp;
    }
}

int main() {
    int cols, rows;
    scanf("%d %d", &cols, &rows);
    char one, zero;
    scanf(" %c %c", &one, &zero);

    unsigned int input_dec;
    int input_bin[32];
    int r = 0, c = 0;
    char print[cols + 1];
    while (scanf("%u", &input_dec) == 1 && r < rows) {
        dec_to_bin(input_dec, input_bin);

        int index = 0;
        while (index < 32) {
            if (r >= rows) {
                break;
            } else if (c >= cols) {
                print[c] = '\0';
                printf("%s\n", print);
                r++;
                c = 0;
            }

            if (input_bin[index] == 1) {
                print[c] = one;
            } else {
                print[c] = zero;
            }
            c++;
            index++;
        }
    }

    if (c > 0 && r < rows) { // print the rest part
        for (int i = c; i < cols; i++) {
            print[i] = zero;
        }
        print[cols] = '\0';
        printf("%s\n", print);
    }

    return 0;
}