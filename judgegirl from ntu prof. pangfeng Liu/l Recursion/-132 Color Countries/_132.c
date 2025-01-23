#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20
#define MAX_C 8

int n, c, p;
int graph[MAX_N][MAX_N]; // Undirected Graph
int color[MAX_N];

bool isValid(int country, int c) {
    for (int i = 0; i < n; i++) {
        // Check if country is adjacent to i and has the same color
        if (graph[country][i] && color[i] == c) { 
            return false;
        }
    }
    return true;
}

bool solve(int country) {
    if (country == n) {
        return true;
    }

    for (int i = 1; i <= c; i++) {
        if (isValid(country, i)) {
            color[country] = i; // Assign color to the current country
            if (solve(country + 1)) {
                return true;
            }
            color[country] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Input data
    scanf("%d %d %d", &n, &c, &p);
    for (int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 0; i < n; i++) {
        color[i] = 0;
    }

    if (solve(0)) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", color[i]);
        }
    } else {
        printf("no solution.\n");
    }

    return 0;
}