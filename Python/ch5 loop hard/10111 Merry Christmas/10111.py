n = int(input())

space = (n - 1) + (n - 2) + (n - 2)

star = 1
for i in range(n):
    print(" " * space, end="")
    print("*" * star)
    if i != n - 1:
        space -= 1
        star += 2
        
space += 1
star -= 2
for i in range(n):
    print(" " * space, end="")
    print("*" * star)
    if i != n - 1:
        space -= 1
        star += 2

space += 1
star -= 2
for i in range(n):
    print(" " * space, end="")
    print("*" * star)
    if i != n - 1:
        space -= 1
        star += 2