import functools
def comp(x, y):
    xy = x + y
    yx = y + x
    if(xy > yx): return -1
    return 1

if __name__ == "__main__":    
    n = int(input())
    s = input().split()
    b = sorted(s, key = functools.cmp_to_key(comp))
    print(''.join(b))
