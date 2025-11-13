matrix = []
for _ in range(2):
    row = list(map(int, input().split()))
    matrix.append(row)

new_rows = len(matrix[0])
new_cols = len(matrix)

for j in range(new_rows):
    new_row = []
    for i in range(new_cols):
        new_row.append(matrix[i][j])
    
    print(*new_row)