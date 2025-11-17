def power(base, exponent):
    if exponent == 0:
        return 1
    
    return base * power(base, exponent - 1)

def main():
    a, b = map(int, input().split())
    print(power(a, b))

if __name__ == "__main__":
    main()