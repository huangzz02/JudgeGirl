import math

while True:
    try:
        x = float(input())
    except EOFError:
        break

    # cos(x) = sigma(n = 0, infinity)((-1)^n * x^(2n) / (2n)!)
    sum10 = 0
    for i in range(10):
        sum10 += ((-1) ** i) * (x ** (2 * i)) / math.factorial(2 * i)

    if abs(sum10 - round(sum10)) < 1e-6:
        print(int(round(sum10)))
    else:
        print(f"{sum10:.4f}")