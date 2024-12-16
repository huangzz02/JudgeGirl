#include <stdio.h>

int main() {
    int start, n1, n2, n3;
    
    while (scanf("%d %d %d %d", &start, &n1, &n2, &n3) == 4) {
        // Break if all numbers are zero
        if (start == 0 && n1 == 0 && n2 == 0 && n3 == 0) break;

        int ans = 0;
        ans += 720; // Turn the dial clockwise for 2 full turns
        ans += ((start - n1 + 40) % 40) * 9; // Continue clockwise to reach the first number
        ans += 360; // Turn the dial counter-clockwise for 1 full turn
        ans += ((n2 - n1 + 40) % 40) * 9; // Continue counter-clockwise to reach the second number
        ans += ((n2 - n3 + 40) % 40) * 9; // Turn clockwise to reach the third number

        printf("%d\n", ans); // Print the total degrees turned
    }
    
    return 0;
}

// (x - y + 40) % 40 is a smarter way