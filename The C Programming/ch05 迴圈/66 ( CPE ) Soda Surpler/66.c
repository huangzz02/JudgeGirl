#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int e, f, c;
        scanf("%d %d %d", &e, &f, &c);
        
        int drink = 0;
        int bottles = e + f;
        
        while (bottles >= c) {
            int new_drinks = bottles / c;
            drink += new_drinks;
            bottles = bottles % c + new_drinks;
        }
        
        printf("%d\n", drink);
    }

    return 0;
}