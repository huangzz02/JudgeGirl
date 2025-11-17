def compatibility(str1, str2):
    combined_str = (str1 + str2).lower()
    data = []
    seen = set()
    for ch in combined_str:
        if ch not in seen:
            seen.add(ch)
            count = combined_str.count(ch)
            for digit in str(count): # easily overlooked
                data.append(int(digit))

    while len(data) > 2:
        if data == [1, 0, 0]:
            return 100
        
        new_data = []
        for i in range(len(data) // 2):
            tmp_add = data[i] + data[-(i + 1)]
            for digit in str(tmp_add):
                new_data.append(int(digit))
        if len(data) % 2 == 1:
            new_data.append(data[len(data) // 2])
        data = new_data

    return data[0] * 10 + data[1]
    # It won't got IndexError, because the len(data) is guaranteed = 2 here.

def main():
    str1 = input()
    str2 = input()
    result = compatibility(str1, str2)
    print(result)

if __name__ == "__main__":
    main()