score = int(input())

if score < 0 or score > 100:
    print("error")
elif score >= 80:
    print("A")
elif score >= 70:
    print("B")
elif score >= 60:
    print("C")
elif score < 60:
    print("F")