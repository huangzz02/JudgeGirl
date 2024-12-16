#include <stdio.h>
#include <string.h>

int check_prize(int digit) {
    switch (digit) {
        case 8: return 200000;
        case 7: return 40000;
        case 6: return 10000;
        case 5: return 4000;
        case 4: return 1000;
        case 3: return 200;
        default: return 0;
    }
}

void remove_first_digit(char *num) {
    memmove(num, num + 1, strlen(num) - 1); 
    num[strlen(num)] = '\0';
}

int main() {
    int special_arr[3], first_arr[3];
    
    for (int i = 0; i < 3; i++) {
        scanf("%d", &special_arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &first_arr[i]);
    }

    int num;
    int total_prize = 0;

    while (scanf("%d", &num) == 1) {
        for (int i = 0; i < 3; i++) {
            if (num == special_arr[i]) {
                total_prize += 2000000;
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            char temp_prize[9];
            sprintf(temp_prize, "%d", first_arr[i]);
            char temp_num[9];
            sprintf(temp_num, "%d", num);
            
            int digit = 8;

            while (digit >= 3) {
                int current_prize = check_prize(digit);

                if (strcmp(temp_num, temp_prize) == 0) {
                    total_prize += current_prize;
                    break;
                } else {
                    remove_first_digit(temp_num);
                    remove_first_digit(temp_prize);
                }

                digit--;
            }
        }
    }

    printf("%d\n", total_prize);
    return 0;
}