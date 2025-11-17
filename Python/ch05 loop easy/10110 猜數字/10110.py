ans = int(input())
min, max = 1, 100

while True:
    print(f"{min} < ? < {max}")
    n = int(input())
    if n <= min or n >= max:
        print("out of range")
    elif n > ans:
        print("wrong answer, guess smaller")
        max = n
    elif n < ans:
        print("wrong answer, guess larger")
        min = n
    else:
        print("bingo answer is", ans)
        break