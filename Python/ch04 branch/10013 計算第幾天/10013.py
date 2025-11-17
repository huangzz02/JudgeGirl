y, m, d = map(int, input().split())

def is_leap(year):
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
if is_leap(y):
    month_days[1] = 29

day_of_year = sum(month_days[:m - 1]) + d

print(day_of_year)