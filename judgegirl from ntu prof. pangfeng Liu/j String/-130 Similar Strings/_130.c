#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char A[81], B[81];
        scanf("%s %s", A, B);

        int lenA = strlen(A);
        int lenB = strlen(B);

        if (strcmp(A, B) == 0) { // Two strings are equal
            printf("yes\n");
        }
        
        else if (lenA == lenB) { // The lengths of the two strings are the same
            char tempA1, tempA2, tempB1, tempB2;
            int count = 0;

            for (int i = 0; i < lenA; i++) {
                if (A[i] != B[i]) {
                    if (count == 0) {
                        tempA1 = A[i];
                        tempB1 = B[i];
                    } else if (count == 1) {
                        tempA2 = A[i];
                        tempB2 = B[i];
                    }
                    count++;
                }
                if (count > 2) {
                    break;
                }
            }

            if (count == 2 && (tempA1 == tempB2 && tempA2 == tempB1)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
        
        else if (abs(lenA - lenB) == 1) { // The lengths of the two strings differ by 1
            if (lenA > lenB) { // Make sure lenA < lenB
                char temp[81];
                strcpy(temp, A);
                strcpy(A, B);
                strcpy(B, temp);
                
                int tempLen = lenA;
                lenA = lenB;
                lenB = tempLen;
            }
            
            for (int i = 0; i < lenB; i++) {
                if (A[i] != B[i]) {
                    memmove(B + i, B + i + 1, lenB - i); // Remember to move '\0'
                    break;
                }
            }

            if (strcmp(A, B) == 0) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
        
        else {
            printf("no\n");
        }
    }

    return 0;
}