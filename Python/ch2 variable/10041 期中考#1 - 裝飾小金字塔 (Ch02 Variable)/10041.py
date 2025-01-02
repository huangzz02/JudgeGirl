char, sep, end = input().split()

for i in range(1, 4):
    spaces = " " * (3 - i)
    content = (char + sep) * (i - 1) + char
    print(spaces + content + spaces + end)
