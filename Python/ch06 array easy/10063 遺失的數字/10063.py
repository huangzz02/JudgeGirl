arr = list(map(int, input().split()))
missing = []

for i in range(arr[0], arr[-1] + 1):
    if i not in arr:
        missing.append(i)

print(*missing)
