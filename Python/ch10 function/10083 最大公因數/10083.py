def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def main():
    a = int(input())
    b = int(input())
    print(gcd(a, b))

if __name__ == "__main__":
    main()