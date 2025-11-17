def fibonacci(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def main():
    n = int(input())
    result = fibonacci(n)
    print(result)

if __name__ == "__main__":
    main()