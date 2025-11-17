n = int(input())
arr = []

sum = 0
for _ in range(n):
    num = int(input())
    arr.append(num)
    sum += num
arr.sort()

for i in arr:
    print(i)
print(f"{sum} {sum/n:.3f}")