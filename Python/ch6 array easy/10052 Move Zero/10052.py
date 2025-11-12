n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
    if arr[i] == 0:
        arr.pop(i)
        arr.append(0)

print(*arr)