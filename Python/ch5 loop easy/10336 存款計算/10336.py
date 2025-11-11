y = int(input())
m = int(input())

if y < 2020 or m < 1 or m > 12:
    print("Invalid input")
else:
    total = 100000.0
    daily_rate = 0.0012 / 365
    interest = 0.0
    
    days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    for _ in range(y - 2020):
        for month in range(6):
            interest += total * daily_rate * days[month]
            total += 10000
        total += interest
        interest = 0
        
        for month in range(6, 12):
            interest += total * daily_rate * days[month]
            total += 10000
        total += interest
        interest = 0

    if m <= 6:
        total += 10000 * (m - 1)
    else:
        for month in range(6):
            interest += total * daily_rate * days[month]
            total += 10000
        total += interest
        interest = 0
        
        total += 10000 * (m - 7)
    # No matter how much 'm' is, the interest for December cannot be received.
    
    print(int(total))