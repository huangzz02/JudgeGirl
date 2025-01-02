#include <stdio.h>

// card.h
void shuffle(int *deck[]);
void print(int *deck[]);

// card.c
void shuffle(int *deck[]) {
    int *a[10000], *b[10000];
    int n = 0, i = 0, j = 0;

    while (deck[n] != NULL) n++;
    if (n == 0) return;

    int mid = (n + 1) / 2;

    for (i = 0; i < mid; i++) a[i] = deck[i];
    for (i = mid; i < n; i++) b[i - mid] = deck[i];
    a[mid] = b[n - mid] = NULL;

    i = j = 0;
    int index = 0;
    while (a[i] != NULL && b[j] != NULL) {
        deck[index++] = a[i++];
        deck[index++] = b[j++];
    }
    while (a[i] != NULL) deck[index++] = a[i++];
    while (b[j] != NULL) deck[index++] = b[j++];
    deck[index] = NULL;
}

void print(int *deck[]) {
    int index = 0;

    if (deck[0] == NULL) {
        return;
    }

    while (deck[index] != NULL) {
        printf("%d", *deck[index]);
        if (deck[index + 1] != NULL) printf(" ");
        index++;
    }
    printf("\n");
}

// main.c
int main() {
    int card[10000];
    int *deck[10000];
    int index = 0;

    while (scanf("%d", &(card[index])) != EOF) {
        deck[index] = &(card[index]);
        index++;
    }
    deck[index] = NULL;
    shuffle(deck);
    print(deck);
    return 0;
}