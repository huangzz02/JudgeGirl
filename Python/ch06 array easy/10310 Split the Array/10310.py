while True:
    try:
        arr = list(map(int, input().split()))
        arr.sort()

        current = None
        count = 0
        for i in arr:
            count += 1
            if i != current:
                current = i
                count = 1
            else:
                if count > 2:
                    print("False")
                    break
        else:
            print("True")
                
    except EOFError:
        break