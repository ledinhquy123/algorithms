import math
def solve(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
        while(res % 10 == 0): res //= 10 # loai bo cac so 0 cua bien res
        res %= 100000000
    print(res % 10)

if __name__ == '__main__':
    n = int(input())
    solve(n)