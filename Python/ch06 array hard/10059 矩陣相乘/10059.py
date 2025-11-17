matrix_a = [] # 2x3
for i in range(2):
    row = list(map(int, input().split()))
    matrix_a.append(row)

matrix_b = [] # 3x2
for i in range(3):
    row = list(map(int, input().split()))
    matrix_b.append(row)

result = [[0, 0], [0, 0]]

for i in range(2):
    for j in range(2):
        for k in range(3):
            result[i][j] += matrix_a[i][k] * matrix_b[k][j]

for row in result:
    print(*row)