n = int(input())
nums = list(map(int, input().split()))
seen = set()
result = []

for i in nums:
    if i not in result and i not in seen:
        result.append(i)
    else:
        seen.add(i)
        if i in result:
            result.remove(i)

print(*result)