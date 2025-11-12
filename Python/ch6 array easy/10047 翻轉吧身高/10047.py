n = int(input())
arr = []

for _ in range(n):
    arr.append(int(input()))

for i in arr[::-1]:
    print(i)