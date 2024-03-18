import math
# Tim so du cua n % 2^x
def solve(n, x):
    res, bin = 0, 1
    while(x != 0):
        res += (n % 2) * bin
        bin *= 2
        n //= 2
        x -= 1
    return res

if __name__ == '__main__':
    n, x = map(int, input().split())
    print(solve(n, x))