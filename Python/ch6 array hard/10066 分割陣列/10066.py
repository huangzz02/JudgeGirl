arr = list(map(int, input().split()))
avg = round(sum(arr) / len(arr))
smaller, bigger = [], []

for num in arr:
    if num < avg:
        smaller.append(num)
    elif num >= avg:
        bigger.append(num)

print(*smaller)
print(*bigger)