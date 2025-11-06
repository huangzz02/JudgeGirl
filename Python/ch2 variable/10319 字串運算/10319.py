A = int(input())
B = int(input())
op = input().strip()

if op == '+':
    result = A + B
elif op == '-':
    result = A - B
elif op == '*':
    result = A * B
elif op == '/':
    result = A // B

print(f"{A} {op} {B} = {result}")