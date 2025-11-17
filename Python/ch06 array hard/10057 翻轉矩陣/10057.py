matrix = [[0 for c in range(3)] for r in range(2)]
new_matrix = [[0 for c in range(2)] for r in range(3)]

for r in range(2):
    row = list(map(int, input().split()))
    for c in range(3):
        matrix[r][c] = row[c]

for r in range(2):
    for c in range(3):
        new_matrix[c][r] = matrix[r][c]

for r in range(3):
    print(*new_matrix[r])