arr = list(map(int, input().split()))

x = 0
for num in arr:
    x ^= num # XOR operation

print(x)