sum = int(input())

if sum < 0:
    print("ERROR")
elif sum < 8000:
    print(f"{sum:.1f}")
elif sum < 18000:
    print(f"{sum * 0.95:.1f}")
elif sum < 28000:
    print(f"{sum * 0.9:.1f}")
elif sum < 38000:
    print(f"{sum * 0.8:.1f}")
else:
    print(f"{sum * 0.7:.1f}")