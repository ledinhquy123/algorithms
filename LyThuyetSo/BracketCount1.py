import math
mod = (int)(1e9 + 7)
def BinPow(a, b, c):
    res = 1
    a %= c
    while(b != 0):
        if(b % 2 == 1):
            res = (res % c) * (a % c)
            res %= c
        a = (a % c) * (a % c)
        a %= c
        b //= 2
    return res

def gt(n):
    res = 1
    for i in range(1, n + 1):
        res = (res % mod) * (i % mod)
        res %= mod
    return res

if __name__ == '__main__':
    n = int(input())
    if(n % 2 == 1):
        print(0)
        exit(0)
    n //= 2
    temp = (gt(n) % mod) * (gt(n + 1) % mod) % mod
    print((gt(2 * n) % mod) * BinPow(temp, mod - 2, mod) % mod)
# (2*n)! / (n!*(n + 1)!)