nums = list(map(int, input().split()))
k = int(input())
result = []

for i in nums:
    if i <= k:
        result.append(i)

print(*result)