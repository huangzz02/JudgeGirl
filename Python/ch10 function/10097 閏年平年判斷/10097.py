def is_leap_year(year):
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

def main():
    year = int(input())
    if is_leap_year(year):
        print(f"西元{year}年是閏年")
    else:
        print(f"西元{year}年是平年")

if __name__ == "__main__":
    main()