def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def main():
    n = int(input())
    result = factorial(n)
    print(result)

if __name__ == "__main__":
    main()