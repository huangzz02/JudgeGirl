sum_arr = []

for _ in range(3):
    data = list(map(int, input().split()))
    sum_arr.append(sum(data))

print(*sum_arr)