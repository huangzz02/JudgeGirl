def find_even_numbers(n, current = 2):
    if current > n:
        return
    print(current)
    find_even_numbers(n, current + 2)

def main():
    n = int(input())
    find_even_numbers(n)

if __name__ == "__main__":
    main()