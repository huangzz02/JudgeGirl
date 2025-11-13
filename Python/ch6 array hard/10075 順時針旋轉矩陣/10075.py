n = int(input())
matrix = []

for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

rotated_matrix = [[0] * n for _ in range(n)]

for r in range(n):
    for c in range(n):
        rotated_matrix[c][n - 1 - r] = matrix[r][c]

for row in rotated_matrix:
    print(*row)

"""
Solution 2:
    n = int(input())
    matrix = []

    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    rotated = list(zip(*matrix[::-1]))

    for row in rotated:
        print(*row)
"""