# Trong python thì không có hàm main nhưng thường dùng : if __name__ == '__main__' : (nhưng các câu lệnh bên dưới phải lùi dòng)
# Chú thích trong python trên 1 dòng :
# Trong python k cần dấu ';' khi kết thúc câu lệnh
# Hàm print có 3 tham số (nội dung, sep, end)
# Có thể in nhiều nội dung
"""
Chú thích trên nhiều dòng có 3 dấu nháy kép
Mặc định sep = ' ', end = '\n'
"""
# Cách in
"""
print('xin chao')
print('xin chao', 'quy') 
print('xin chao', 'nhung', sep = '#')
print('xin chao', 'hello', 'hi', sep = '@')
print('xin chao', 'hello', 'hi', sep = '\n', end = '&')
print('quy nhung', end = '\n')
"""

# Kiểu dữ liệu và biến
"""
Trong python không cần xác định kiểu dữ liệu cho biến
Trong python có kiểu số phức complex
"""
"""
a = 100
b = 'hello'
c = 3.8
# In ra kiểu dữ liệu
print(type(a), type(b), type(c))
"""
"""
a = 28
b = 2.8
c = 14 + 28j
print(type(a), type(b), type(c), sep = '\n')
"""

# Trong python số nguyên không bị giới hạn
"""
a = 2318476328975610834675891326598163485689134659816345908136750491
print(a)
"""

# Trong python có thể in ra chuyển đổi giữa hê 2, 8, 16 (binary, oct, hexadecimal)
"""
print(0b1101) # hoặc print(0B1101)
print(0o1023231)
print(0x42699)
"""

"""
Trong python thì float có giới hạn từ 5*10^-342 tới 1.8*10^308
quá ngưỡng trên thì vô cùng inf còn ngưỡng dưới 0
"""
"""
a = 3e5
b = 3e-2
print(a, b, sep = '\n')
print(type(a), type(b))
print(2e308)
print(6e-342)
"""

# Làm tròn sau dấu thập phân
"""
a = 20.083405740276
print('%.3f' % a)
print(round(a, 3))
print('{:.3f}'. format(a))
"""

# Số phức
"""
a = 5 + 10j
print(a.real)
print(a.imag)
"""
 
# Kiểu đúng sai bool
# Số tương tự c++ còn chuỗi thì chuỗi rỗng là False, ngược lại là True
"""
a = True
b = False
print(type(a), type(b))
print(bool(100), bool(0), bool('hello'), bool(''))
"""

# Xâu kí tự
s = 'hello'
# Có thể in được xâu có dấu
t = """
day la noi dung cua xau t
"""
# print(type(s), type(t), sep = '\n')

# Ép kiểu
"""
# Ép sang int
b = 12.8 
a = int(b)
print(a)
c = '000017652387462348762'
a = int(c)
print(a)
c = '12345@' # lỗi

# Ép sang float
a = 10
b = float(a)
print(b)
a = '2134786234.348597345'
b = float(a)
print(b)

# Ép sang str
a = 123
s = str(123)
print(type(s), s)
a = 1234.34535
s = str(a)
print(s)

# Ép sang bool
a = 0
b = bool(a)
print(b)
"""

