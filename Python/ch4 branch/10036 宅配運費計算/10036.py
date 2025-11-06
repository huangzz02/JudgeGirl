w, d = map(int, input().split())
price = 100;

if w > 20:
    print("不收件")
else:
    if w < 5:
        if d >= 10:
            price += d * 10
    elif w < 10:
        price += d * 20
    else:
        price += d * 40
    
    print(price)