i = int(input())
j = int(input())
matrix = []

for r in range(i):
    row = list(map(int, input().split()))
    matrix.append(row)

sum = 0
for r in range(i):
    sum += matrix[r][r]

print(f"{sum / i:.2f}")