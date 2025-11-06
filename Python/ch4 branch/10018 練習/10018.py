x = int(input())

if 100 <= x <= 999:
    hundreds = x // 100
    tens = (x // 10) % 10
    ones = x % 10

    if x % 2 == 0:
        print(hundreds * tens * ones)
    else:
        print(hundreds + tens + ones)