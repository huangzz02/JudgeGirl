tri_func, deg = map(str, input().split())
deg = int(deg)

if tri_func not in ("sin", "cos") or deg < 0:
    print("Please follow the input format!")
    exit()

# deg = 90 * n + a
n = deg // 90
a = deg % 90 # or needless

# sin: ++-- -> 1st +, 2nd +, 3rd -, 4th -
# cos: +--+ -> 1st +, 2nd -, 3rd -, 4th +
sign_map = {
    "sin": ["", "", "-", "-"],
    "cos": ["", "-", "-", ""]
}
sign = sign_map[tri_func][n % 4]

# Odd changes, even remains the same
if n % 2 != 0:
    tri_func = "cos" if tri_func == "sin" else "sin"

print(f"{sign}{tri_func} {a}")