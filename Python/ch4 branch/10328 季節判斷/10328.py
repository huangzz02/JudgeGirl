month = int(input())

if month in [3, 4, 5]:
    print(f"Month {month} is spring.")
elif month in [6, 7, 8]:
    print(f"Month {month} is summer.")
elif month in [9, 10, 11]:
    print(f"Month {month} is fall.")
else:
    print(f"Month {month} is winter.")