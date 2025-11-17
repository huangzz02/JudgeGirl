def shift_letter(str):
    direction = str[0]
    shift = int(str[1])
    letter = str[2]

    base = ord('A')

    if direction == '+':
        new_position = (ord(letter) - base + shift) % 26
    elif direction == '-':
        new_position = (ord(letter) - base - shift) % 26

    new_letter = chr(base + new_position)
    return new_letter

def main():
    input_str = input()
    result = shift_letter(input_str)
    print(result)

if __name__ == "__main__":
    main()