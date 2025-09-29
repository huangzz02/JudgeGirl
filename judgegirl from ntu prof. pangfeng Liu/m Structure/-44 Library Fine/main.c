#include <stdio.h>
#include "book.h"
#include "date.h"
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned);

unsigned int importance_factor(unsigned int n) {
    int first = -1, second = -1;
    for (int i = 0; i < 32; i++) {
        if (n & (1u << i)) {
            if (first == -1) {
                first = i;
            } else {
                second = i;
                break;
            }
        }
    }
    return (second - first - 1);
    /*
        example: n = 17 (binary 00000000000000000000000000010001)

        Note: 1u << i -> 00000000000000000000000000001 when i = 0
              1u << i -> 00000000000000000000000000010 when i = 1
              1u << i -> 00000000000000000000000000100 when i = 2
              1u << i -> 00000000000000000000000001000 when i = 3
              1u << i -> 00000000000000000000000010000 when i = 4
              ...

        i = 0: n & (1u << 0) -> true, first = 0
        i = 1: n & (1u << 1) -> false
        i = 2: n & (1u << 2) -> false
        i = 3: n & (1u << 3) -> false
        i = 4: n & (1u << 4) -> true, second = 4, break
        
        Note: 00000000000000000000000000010001
                                         ^   ^
                                     second first
        
        return (4 - 0 - 1) -> 3
    */
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_borrowed = 0, days_returned = 0;

    for (int i = 0; i < date_borrowed.year; i++) {
        days_borrowed += 365;
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            days_borrowed += 1;
        }
    }
    for (int i = 0; i < date_borrowed.month; i++) {
        days_borrowed += month_days[i];
        if (i == 2 && ((date_borrowed.year % 4 == 0 && date_borrowed.year % 100 != 0) || (date_borrowed.year % 400 == 0))) {
            days_borrowed += 1;
        }
    }
    days_borrowed += date_borrowed.day;

    for (int i = 0; i < date_returned.year; i++) {
        days_returned += 365;
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            days_returned += 1;
        }
    }
    for (int i = 0; i < date_returned.month; i++) {
        days_returned += month_days[i];
        if (i == 2 && ((date_returned.year % 4 == 0 && date_returned.year % 100 != 0) || (date_returned.year % 400 == 0))) {
            days_returned += 1;
        }
    }
    days_returned += date_returned.day;

    int days_late = days_returned - days_borrowed + 1;
    unsigned int factor = importance_factor(book.importance);
    int fine = 0;

    if (days_late > 0) {
        switch (book.type) {
            case NOVEL:
                if (days_late > 90) fine = (days_late - 90) * factor;
                break;
            case COMICS:
                if (days_late > 10) fine = (days_late - 10) * factor;
                break;
            case MANUAL:
                if (days_late > 100) fine = (days_late - 100) * factor;
                break;
            case TEXTBOOK:
                if (days_late > 5) fine = (days_late - 5) * factor;
                break;
        }
    }

    return fine;
}

int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 11;
    date_borrowed.day   = 14;
    date_returned.year  = 2007;
    date_returned.month = 12;
    date_returned.day   = 3;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}