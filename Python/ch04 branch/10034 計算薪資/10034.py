time = int(input())

if time <= 60:
    salary = time * 100
elif time < 76:
    salary = 60 * 100 + (time - 60) * 125
else:
    salary = 60 * 100 + 15 * 125 + (time - 75) * 175

print(salary)