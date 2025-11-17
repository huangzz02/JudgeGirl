money = int(input())
milk = int(input())
lamb = int(input())
chocolate = int(input())

left = money - (milk * 145 + lamb * 90 + chocolate * 46)
if left < 0:
    print("Insufficient funds")
else:
    print(left)