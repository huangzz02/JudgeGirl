data = list(map(int, input().split()))

n = len(data)
for i in range(n):
    for j in range(0, n - i - 1):
        if data[j] < data[j + 1]:
            data[j], data[j + 1] = data[j + 1], data[j]

print(*data)
# or print(' '.join(map(str, data)))