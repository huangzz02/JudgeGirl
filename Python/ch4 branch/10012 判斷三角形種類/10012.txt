a, b, c = map(int, input().split())

if a > b:
    a, b = b, a
if a > c:
    a, c = c, a
if b > c:
    b, c = c, b

if a + b <= c:
    print("not a triangle")
elif a == b and b == c:
    print("regular triangle")
elif a * a + b * b == c * c:
    print("rectangular triangle")
elif a * a + b * b < c * c:
    if a == b:
        print("isosceles obtuse triangle")
    else:
        print("obtuse triangle")
elif a * a + b * b > c * c:
    if a == b or b == c:
        print("isosceles acute triangle")
    else:
        print("acute triangle")