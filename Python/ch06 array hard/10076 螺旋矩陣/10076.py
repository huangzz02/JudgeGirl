n = int(input())
matrix = matrix = [[0]*n for _ in range(n)]

current_num = 1
top, bottom, left, right = 0, n - 1, 0, n - 1

while current_num <= n * n:
    for i in range(left, right + 1):
        matrix[top][i] = current_num
        current_num += 1
    top += 1

    for i in range(top, bottom + 1):
        matrix[i][right] = current_num
        current_num += 1
    right -= 1

    for i in range(right, left - 1, -1):
        matrix[bottom][i] = current_num
        current_num += 1
    bottom -= 1

    for i in range(bottom, top - 1, -1):
        matrix[i][left] = current_num
        current_num += 1
    left += 1

for row in matrix:
    print(*row)