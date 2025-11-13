n = int(input())
matrix = [[0 for c in range(n)] for r in range(n)]
# or matrix = [[0] * n for _ in range(n)]

for r in range(n):
    for c in range(n):
        matrix[r][c] = r * c

for row in matrix:
    print(*row)