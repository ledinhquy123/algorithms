# tim vi tri dau tien lon hon x
def solve(a, l, r, x, n):
    res = n
    while(l <= r):
        m = (l + r) // 2
        if(a[m] > x):
            res = m
            r = m - 1
        else: l = m + 1
    return res

if __name__ == '__main__':
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    for i in range(m):
        it = solve(a, 0, n - 1, b[i], n)
        if(it == 0): print(-1)
        else:
            it -= 1
            print(a[it])
            a.pop(it)
            n -= 1

        