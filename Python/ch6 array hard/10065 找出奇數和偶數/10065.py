arr = list(map(int, input().split()))
odd, even = [], []

for num in arr:
    if num % 2 == 0:
        even.append(num)
    else:
        odd.append(num)

odd.sort()
even.sort()
print(*odd)
print(*even)