col = int(input())

for i in range(1, col + 1):
    ch = "1" if i % 2 != 0 else "0"
    for j in range(i):
        print(ch, end="")
        ch = "0" if ch == "1" else "1"
    print()