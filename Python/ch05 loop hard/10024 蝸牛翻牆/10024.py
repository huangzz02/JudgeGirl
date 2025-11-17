a, b, c, d = map(int, input().split())
remain = a - b
count = 1

while True:
    if remain - c <= 0:
        break
    remain += - c + d
    count += 1

print(count)