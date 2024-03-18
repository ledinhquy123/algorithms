import math
def solve(p, x):
    res = 1
    while(x != 0):
        if(x % 2 == 1):
           res = ((res % 10) * (p % 10)) % 10
        p = ((p % 10) * (p % 10)) % 10
        x //= 2 
    return res

if __name__ == '__main__':
    p, x = map(int, input().split())
    print(solve(p, x))