arr = list(map(int, input().split()))
index = []

for i in range(len(arr)):
    if arr[i] == 7:
        index.append(i)

print(*index)