money = int(input())

if money < 0:
    print("error")
else:
    coins = [1000, 500, 100, 50, 10, 5, 1]
    for c in coins:
        count = money // c
        if count > 0:
            money %= c
            print(f"{c}: {count}")