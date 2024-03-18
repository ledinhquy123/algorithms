# Toán tử

# Gán
"""
a = 100
b = a
c = b
print(a, b, c)
a, b, c = 100, 200, 300
print(a, b, c)
"""
# Toán tử toán học
"""
a = 30
b = 7
c = a / b
print(c)
c = a // b
print(c)

a = 30.0
b = 7.0
r = a % b
print(r)

a = 2**10 # Lũy thừa 2 ^ 10
print(a)
"""

# Nhập từ bàn phím
"""
a = input('Nhap a: ') # a = input()
print(type(a)) # Hàm input sẽ trả về kiểu str
print('Gia tri cua bien a vua nhap la: ', a)
b = int(input('Nhap gia tri cua b: ')) # ép kiểu sang int
print(type(b), 'Gia tri cua b: ', b)
"""
# float tương tự int

# Nhập chiều dài, rộng trên 2 dòng và in ra chu vi, diện tích
# Phaỉ ép kiểu sang int mới tính toán được
"""
a = int(input())
b = int(input())
chuivi = (a + b) * 2
dientich = a * b
print(chuivi, dientich)

"""
# Nhập nhiều số trên cùng 1 dòng
"""
x , y, z = map(int, input().split())
print(x, y, z, sep = '\n')
"""

# Toán tử so sánh
"""
print(10 < 20)
print(10 == 10)
print(10 != 5)
print(10 == 202)
print(10 <= 10)
"""

# Toán tử logic
"""
print((2 <= 28) and (3 == 3))
print((28 == 14) or (8 == 2))
print((20 == 20) or (30 == 30))
print(not(20 == 20))
"""

# Hàm toán học
"""
import math
print(math.sqrt(100))
print(math.factorial(3)) # Tính giai thừa
print(math.fmod(12, 3)) # Hàm chia dư
print(math.ceil(3.2))
print(math.floor(3.5))
print(round(3.6)) # Khác hàm round làm tròn sau dấu thập phân
print(math.pow(2, 10))
print(math.isqrt(10))
"""
# print(help(math)) : hiện ra các hàm trong math


