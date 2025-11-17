stones = list(map(int, input().split()))

while True:
    try:
        num = stones[0]
        for _ in range(3):
            stones.remove(num)
    except:
        result = num
        break

print(result)