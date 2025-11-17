N = int(input())

if N <= 560000:
    tax = int(N * 0.05)
elif N <= 1260000:
    tax = int(N * 0.12 - 39200)
elif N <= 2520000:
    tax = int(N * 0.20 - 140000)
elif N <= 4720000:
    tax = int(N * 0.30 - 392000)
else:
    tax = int(N * 0.40 - 864000)

print(f"The total annual tax payable is {tax} dollars.")