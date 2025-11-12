arr = list(map(int, input().split()))

count = {}
for num in arr:
    count[num] = count.get(num, 0) + 1

repeated = []
for num in count:
    if count[num] > 1:
        repeated.append(num)

repeated.sort()
print(*repeated)