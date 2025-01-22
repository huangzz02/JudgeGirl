#include <stdio.h>
#include <string.h>

int hasEOF = 0;

int readchar() {
    static int N = 1 << 20;
    static char buf[1 << 20]; // Buffer for reading data from standard input
    static char *p = buf, *end = buf;

    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) { // fread will return 0 after all data has been read
            hasEOF = 1;
            return EOF;
        }
        p = buf;
    }
    
    return *p++;
}

int ReadInt(int *x) {
    char c, neg;

    while((c = readchar()) < '-') {
        if(c == EOF) return 0;
    }
    
    neg = (c == '-') ? -1 : 1; // check positive and negative
    *x = (neg == 1) ? c - '0' : 0;

    while((c = readchar()) >= '0') {
        *x = (*x << 3) + (*x << 1) + (c - '0'); // = x * 10 + c = x * (2^3 + 2^1) + c
    }
    *x *= neg;

    return 1;
}

int main() {
    long long int books = 0;
    int x;

    while (ReadInt(&x)) {
        int found = 0;
        for (int i = 0; i < 8; i++) {
            int currentBook = (books >> (8 * (7 - i))) & 0xFF;

            /*
                If "books" is : 0x0102030405060708

                i = 0, currentBook = 0x0000000000000001 & 0xFF = 0x01(bin: 0000 0001, 8 byte),
                i = 1, currentBook = 0x0000000000000102 & 0xFF = 0x02(bin: 0000 0010, 8 byte),
                i = 2, currentBook = 0x0000000000010203 & 0xFF = 0x03(bin: 0000 0011, 8 byte),
                ... ,
                i = 7, currentBook = 0x0102030405060708 & 0xFF = 0x08(bin: 0000 1000, 8 byte)

                (So the value of currentBook is between 0x00 ~ 0xFF(dec: 0 ~ 255))
            */

            if (currentBook == x) {
                found = 1;
                
                long long int leftMask = (i == 0) ? 0 : ~((1LL << (8 * (7 - i + 1))) - 1);
                long long int rightMask = (i == 7) ? 0 : (1LL << (8 * (7 - i))) - 1;

                /*
                    Normal case:
                        ex: i = 4 

                        leftMask:
                        1LL << (8 * (7 - i + 1))          = 0x0000000100000000
                        ((1LL << (8 * (7 - i + 1))) - 1)  = 0x00000000FFFFFFFF
                        ~((1LL << (8 * (7 - i + 1))) - 1) = 0xFFFFFFFF00000000

                        rightMask:
                        1LL << (8 * (7 - i))              = 0x0000000001000000
                        (1LL << (8 * (7 - i))) - 1        = 0x0000000000FFFFFF

                        in the end,
                        leftMask  = 0xFFFFFFFF00000000
                        rightMask = 0x0000000000FFFFFF

                    Special case:
                        i = 0
                        leftMask  = 0x0000000000000000
                        rightMask = 0x00FFFFFFFFFFFFFF

                        i = 7
                        leftMask  = 0xFFFFFFFFFFFFFF00
                        rightMask = 0x0000000000000000
                */

                                                              // If i = 4
                long long int leftBooks = books & leftMask;   // leftBooks  = 0x0102030400000000
                long long int rightBooks = books & rightMask; // rightBooks = 0x0000000000060708
                rightBooks = rightBooks << 8;                 // rightBooks = 0x0000000006070800
                books = leftBooks | rightBooks;

                /*
                    leftBooks    = 0x0102030400000000
                    rightBooks   = 0x0000000006070800

                    books        = 0x0102030406070800
                */

                /*
                    The '&' operator sets the bit to 1 when both bits are 1, and 0 for all other conditions.
                    Example:
                        int a = 0b11001010;
                        int b = 0b10101100;
                        a &= b;  // a becomes 0b10001000

                    The '|' operator sets the bit to 0 when both bits are 0, and 1 for all other conditions.
                    Example:
                        int a = 0b11001010;
                        int b = 0b10101100;
                        a |= b;  // a becomes 0b11101110
                */

                break;
            }
        }

        int insertPos = -1;
        for (int i = 0; i < 8; i++) {  // Find the first empty seat from left to right
            if (((books >> (8 * (7 - i))) & 0xFF) == 0) {
                insertPos = i;
                break;  // Stop at the first empty spot
            }
        }

        if (!found && insertPos == -1) { // If it is not on the bookshelf and there is no space
            books = books << 8;
            books |= (long long int)x;
            // example 1
        } else {
            books |= ((long long int)x << (8 * (7 - insertPos)));
            // example 2, 3, 4
        }
        
        /*
            example 1 (x found, x insert): // note the last two place of books at first isn't 00
                books          = 0x0102030405060708 (dec: 1,2,3,4,5,6,7,8)
                (long long)x   = 0x00000000000000CC (dec: 0,0,0,0,0,0,0,204)

            ->  books          = 0x02030405060708CC (dec: 2,3,4,5,6,7,8,204)

            example 2 (x found, o insert): 
                books          = 0x0102030400000000 (dec: 1,2,3,4,0,0,0,0)
                (long long)x   = 0x00000000000000CC (dec: 0,0,0,0,0,0,0,204)

            ->  books          = 0x01020304CC000000 (dec: 1,2,3,4,204,0,0,0)

            example 3 (o found, x insert):
                books (masked) = 0x0102040506070800 (dec: 1,2,4,5,6,7,8,0)
                (long long)x   = 0x0000000000000003 (dec: 0,0,0,0,0,0,0,3)

            ->  books          = 0x0102030405060703 (dec: 1,2,4,5,6,7,8,3)

            example 4 (o found, o insert):
                books (masked) = 0x0102040000000000 (dec: 1,2,4,0,0,0,0,0)
                (long long)x   = 0x0000000000000003 (dec: 0,0,0,0,0,0,0,3)

            ->  books          = 0x0102040300000000 (dec: 1,2,4,3,0,0,0,0)
        */
    }

    int finalBooks[8];
    int countZeros = 0;
    for (int i = 7; i >= 0; i--) {
        int bookID = (books >> (8 * i)) & 0xFF;
        if (bookID == 0) countZeros++;
        finalBooks[7 - i] = bookID;
    }

    memmove(finalBooks + countZeros, finalBooks, (8 - countZeros) * sizeof(int));
    memset(finalBooks, 0, countZeros * sizeof(int));

    /*
        If the dec is 1,2,3,4,5,0,0,0
        We need to turn this into 0,0,0,1,2,3,4,5
        Because the book should be put at the far right place of bookshelf after reading it
    */

    for (int i = 0; i < 8; i++) {
        printf("%d", finalBooks[i]);
        if (i < 7) printf(" ");
    }
    printf("\n");

    return 0;
}