m = int(input())

for case in range(m):
    i, j = map(int, input().split())
    max_cycle = 0
    for k in range(i, j + 1):
        count = 1
        while k != 1:
            if k % 2 == 0:
                k //= 2
            else:
                k = 3 * k + 1
            count += 1
        max_cycle = max(max_cycle, count)

    print(max_cycle)