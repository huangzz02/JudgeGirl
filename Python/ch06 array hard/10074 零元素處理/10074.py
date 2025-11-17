m = int(input())
n = int(input())
matrix = []

for _ in range(m):
    row = list(map(int, input().split()))
    matrix.append(row)

rows_to_zero = set()
cols_to_zero = set()

for r in range(m):
    for c in range(n):
        if matrix[r][c] == 0:
            rows_to_zero.add(r)
            cols_to_zero.add(c)

for r in rows_to_zero:
    matrix[r] = [0] * n

for c in cols_to_zero:
    for r in range(m):
        matrix[r][c] = 0

for row in matrix:
    print(*row)