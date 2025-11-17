num1 = float(input())
num2 = float(input())

result = (num1 + num2) ** 2

if result.is_integer():
    print(int(result))
else:
    print(result)