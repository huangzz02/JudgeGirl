counts = [int(input()) for _ in range(10)]

items = [(-counts[i], i) for i in range(10)]
# (-times, digit), negative for descending order by times

items.sort()

for _, digit in items:
    print(digit)