a = int(input())
b = int(input())
op = input().strip()

if op == "+":
    print(a + b)
elif op == "-":
    print(a - b)
elif op == "*": 
    print(a * b) 
# The asterisk given in the title is "∗" (Unicode U+2217) rather than "*" (ASCII 42)
# And this is an issue with the problem itself, "*" (ASCII 42) still needs to be used here.
elif op == "/":
    result = a / b
    if result.is_integer():
        print(int(result))
    else:
        print(f"{result:.1f}")
elif op == "//":
    print(a // b)
elif op == "%":
    print(a % b)